/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:46:02 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/28 13:44:56 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <sys/stat.h>
#include <unistd.h>
// #include <string.h>
// #include <stdio.h>
// #include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <termios.h>

typedef struct s_cmd
{
	char	*cmd;
	char	**arg;
}	t_cmd;

typedef struct s_dict
{
	char *key;
	char *value;
}	t_dict;

typedef struct s_mdata
{
	void			*data;
	struct s_mdata	*next;
}	t_mdata;

typedef struct s_mlist
{
	void	*head;
	int		size;
}	t_mlist;

typedef struct s_minfo
{
	t_mlist	*env_list;
	char	*home;
	int		sc;
}	t_minfo;

void	signal_checksum(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	null_exit()
{
	printf("exit\n");
	exit(1);
}

void	init_mlist(t_mlist *list)
{
	list->head = 0;
	list->size = 0;
}

void	init_env(t_dict *env, char *key, char *value)
{
	env->key = key;
	env->value = value;
}

void	free_temp(char **temp)
{
	free(temp[0]);
	free(temp[1]);
	free(temp);
}

int list_add_back(t_mlist *list, t_mdata *data)
{
	t_mdata	*cur;

	cur = 0;
	if (list->size == 0)
	{
		list->head = data;
		list->size = 1;
	}
	else
	{
		cur = list->head;
		while (cur->next)
			cur = cur->next;
		cur->next = data;
		list->size++;
	}
	return (1);
}

int	add_data_to_list(t_mlist *list, void *data)
{
	t_mdata	*mdata;

	mdata = (t_mdata *)malloc(sizeof(t_mdata));
	mdata->data = data;
	mdata->next = 0;
	return (list_add_back(list, mdata));
}

int	parse_env(t_mlist *env_list, char **envp)
{
	char	**temp;
	int		index;
	t_dict	*env;

	index = 0;
	while (envp[index])
	{
		env = malloc(sizeof(t_dict));
		temp = ft_split(envp[index], '=');
		init_env(env, ft_strdup(temp[0]), ft_strdup(temp[1]));
		free_temp(temp);
		add_data_to_list(env_list, env);
		index++;
	}
	return (0);
}

int		ft_strcmp(const char *a, const char *b)
{
	if (!a && b)
		return (-(*b));
	else if (a && !b)
		return (*a);
	while ((*a || *b) && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

char	*get_value_dict(t_mlist *list, char *key)
{
	t_mdata	*cur;
	t_dict	*dict;

	if (!list)
		return (0);
	cur = list->head;
	while (cur)
	{
		dict = cur->data;
		if (!ft_strcmp(dict->key, key))
			return (dict->value);
		cur = cur->next;
	}
	return (0);
}

int	ft_cd(char *path, t_minfo *info)
{
	int		err;

	if (path)
		err = chdir(path);
	else
		err = chdir(info->home);
	if (err == -1)
		printf("cd fail\n");
	return (0);
}

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("%s\n", path);
	return (0);
}

int	ft_echo(char *str)
{
	printf("%s\n", str);
}

int	init_minishell(t_minfo *info, char **envp)
{
	int	err;

	err = 0;
	init_mlist(info->env_list);
	err = parse_env(info->env_list, envp);
	info->home = get_value_dict(info->env_list, "HOME");
	return (err);
}

int main(int argc, char **argv, char **envp)
{
	char	*str;
	t_minfo	info;

	if (!argc || !argv)
		return ;
	signal(SIGINT, signal_checksum);
	signal(SIGQUIT, SIG_IGN);
	init_minishell(&info, envp);
	while (1)
	{
		str = readline("woonchoi$> ");
		add_history(str);
		if (str == NULL)
			null_exit();
		ft_cd("..", &info);
		ft_pwd();
		// printf("%s\n", str);
		// exec_line(str);
		free(str);
	}
}