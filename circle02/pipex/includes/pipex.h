/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:38:17 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/07 14:50:06 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_cmd
{
	char	*cmd;
	char	**option;
}	t_cmd;

typedef struct s_info
{
	int		fd_infile;
	int		fd_outfile;
	int		fd_pipe[2];
	char	**env_path;
	t_cmd	parent;
	t_cmd	child;
}	t_info;

void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *src);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

void	free_ptr(void *ptr);
void	free_vec(void **vec);
void	free_parents(t_info *info);
void	free_child(t_info *info);

int		env_parse(char **envp, char ***ret);
char	*cmd_join(char *cmd, char **path);
void	child_cmd_parse(char *cmd, char **envp, t_info *info);
void	parents_cmd_parse(char *cmd, char **envp, t_info *info);

void	child_process(char **argv, char **envp, t_info *info);
void	parents_process(char **argv, char **envp, t_info *info, pid_t *pid);
void	pipex_process(char **argv, char **envp, t_info *info);
void	check_args(int argc, t_info *info);

#endif