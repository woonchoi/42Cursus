/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:44:53 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/07 15:36:56 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, t_info *info)
{
	info->fd_infile = open(argv[1], O_RDONLY);
	if (info->fd_infile < 0)
	{
		ft_putendl_fd("File1(infile) does not exist", STDERR_FILENO);
		exit(1);
	}
	close(info->fd_pipe[0]);
	dup2(info->fd_pipe[1], STDOUT_FILENO);
	close(info->fd_pipe[1]);
	dup2(info->fd_infile, STDIN_FILENO);
	child_cmd_parse(argv[2], envp, info);
	if (execve(info->child.cmd, info->child.option, envp) == -1)
	{
		ft_putstr_fd("Child command not found: ", STDERR_FILENO);
		ft_putendl_fd(info->child.option[0], STDERR_FILENO);
		free_child(info);
		exit(1);
	}
}

void	parents_process(char **argv, char **envp, t_info *info, pid_t *pid)
{
	waitpid(*pid, 0, WNOHANG);
	info->fd_outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->fd_outfile < 0)
	{
		ft_putendl_fd("File2(outfile) does not exist", STDERR_FILENO);
		exit(1);
	}
	close(info->fd_pipe[1]);
	dup2(info->fd_pipe[0], STDIN_FILENO);
	close(info->fd_pipe[0]);
	dup2(info->fd_outfile, STDOUT_FILENO);
	parents_cmd_parse(argv[3], envp, info);
	if (execve(info->parent.cmd, info->parent.option, envp) == -1)
	{
		ft_putstr_fd("Parents command not found: ", STDERR_FILENO);
		ft_putendl_fd(info->parent.option[0], STDERR_FILENO);
		free_parents(info);
		exit(1);
	}
}

void	pipex_process(char **argv, char **envp, t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("Fork process failed", STDERR_FILENO);
		exit(1);
	}
	else if (pid == 0)
		child_process(argv, envp, info);
	else if (pid > 0)
		parents_process(argv, envp, info, &pid);
}
