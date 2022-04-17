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

typedef struct	s_plist
{
	int				type;
	char			*str;
	struct s_mlist	*next;
}	t_plist;

typedef struct	s_ptree
{

}	t_ptree;

typedef struct	s_cmd_parse
{
	// t_mlist	*head;
	t_ptree	*root;
	int		error;
	int		count_pipe;
}	t_cmd_parse;

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

int	init_minishell(char **envp)
{

}

int	ft_parser(char *str)
{

}

int main(int argc, char **argv, char **envp)
{
	char	*str;
	char	arr[2][100] = {"/bin/ls", "-al"};

	if (!argc || !argv)
		return ;
	signal(SIGINT, signal_checksum);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("woonchoi$> ");
		add_history(str);
		if (str == NULL)
			null_exit();
		execve("/bin/ls", &"/bin/ls", envp);
		// printf("%s\n", str);
		// exec_line(str);
		free(str);
	}
}
