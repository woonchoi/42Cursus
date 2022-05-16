# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h> 
# include "libft.h"

int	g_exit_status;

static void	sigint_handler(pid_t pid)
{
	if (pid == -1)
	{
		ft_putendl_fd("", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else
		ft_putendl_fd("", STDOUT_FILENO);
	g_exit_status = 130;
}

static void	sigquit_handler(void)
{
	ft_putstr_fd("Quit: 3", STDERR_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	signal_handler(int signum)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signum == SIGINT)
		sigint_handler(pid);
	else if (signum == SIGQUIT)
		sigquit_handler();
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

char	*readline_sig()
{
	char	*line;

	signal(SIGQUIT, SIG_IGN);
	line = readline("tinyshell$ ");
	set_signal();
	return (line);
}

void	prompt()
{
	char	*line;

	while (1)
	{
		line = readline_sig();
		if (!line)
		{
			rl_replace_line("", 0);
			printf("exit\n");
			exit(0);
		}
		add_history(line);
		printf("%s\n", line);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	set_signal();
	prompt();
}