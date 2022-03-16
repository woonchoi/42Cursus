/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:13:22 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:14:13 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
# define ERROR 0
# define FALSE 0
# define TRUE 1

typedef pthread_mutex_t	t_mu;
typedef pthread_t		t_th;

typedef struct s_info
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_count;
	int			eat_finish;
	int			finish;
	int			err;
	int			*forks_arr;
	long long	start_time;
	t_mu		*forks;
	t_mu		print;
	t_mu		eating;
	t_mu		waiting;
}	t_info;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	long long	time_check;
	t_info		*info;
	t_th		thread_id;
}	t_philo;

typedef struct s_table
{
	t_info	info;
	t_philo	*philos;
}	t_table;

long long	ft_get_time(void);
void		check_time(t_info *info, int mode);

int			ft_isspace(char c);
int			ft_isdigit(char c);
int			check_input(const char *str);
int			arg_check(t_table *table, int argc, char **argv);

int			ft_strlen(char *s);
int			ft_atoi(const char *str, int *ret);

void		free_all(t_table *table);
int			init_all(t_table *table);

void		philo_print(char *msg, t_info *info, int philo_id);
int			print_err(char *errmessage);

int			philo_eat(t_info *info, t_philo *philo);
void		*routine(void *philo);
void		philosophers(t_table *table);

#endif
