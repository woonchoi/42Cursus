/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:37:38 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/07 15:25:01 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_args(int argc, t_info *info)
{
	if (argc != 5)
	{
		ft_putendl_fd("Syntax error", STDERR_FILENO);
		exit(1);
	}
	if (pipe(info->fd_pipe) == -1)
	{
		ft_putendl_fd("Pipe process failed", STDERR_FILENO);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	check_args(argc, &info);
	pipex_process(argv, envp, &info);
	return (0);
}
