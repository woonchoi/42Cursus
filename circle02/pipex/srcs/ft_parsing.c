/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:57:51 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/07 14:50:59 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	env_parse(char **envp, char ***ret)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (envp[i])
	{
		temp = ft_strnstr(envp[i], "PATH=", 6);
		if (temp == envp[i])
			break ;
		i++;
	}
	(*ret) = ft_split(&(envp[i][5]), ':');
	if (!ret)
		return (FALSE);
	return (TRUE);
}

char	*cmd_join(char *cmd, char **path)
{
	int		i;
	char	*temp;
	char	*ret;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		ret = ft_strjoin(temp, cmd);
		if (!access(ret, X_OK))
			return (ret);
		free_ptr(temp);
		free_ptr(ret);
		i++;
	}
	return (NULL);
}

void	child_cmd_parse(char *cmd, char **envp, t_info *info)
{
	char	**args;

	args = ft_split(cmd, ' ');
	info->child.option = args;
	info->child.cmd = NULL;
	if (args[0][0] == '/')
		info->child.cmd = ft_strdup(args[0]);
	else
	{
		if (env_parse(envp, &(info->env_path)))
			info->child.cmd = cmd_join(args[0], info->env_path);
	}
}

void	parents_cmd_parse(char *cmd, char **envp, t_info *info)
{
	char	**args;

	args = ft_split(cmd, ' ');
	info->parent.option = args;
	info->parent.cmd = NULL;
	if (args[0][0] == '/')
		info->parent.cmd = ft_strdup(args[0]);
	else
	{
		if (env_parse(envp, &(info->env_path)))
			info->parent.cmd = cmd_join(args[0], info->env_path);
	}
}
