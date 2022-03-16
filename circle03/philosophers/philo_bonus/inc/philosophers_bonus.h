/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:13:22 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:22:14 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef pthread_t		t_th;

typedef struct s_info
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_count;
	pid_t		check_pid;
	long long	start_time;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*eating;
	sem_t		*ready;
	sem_t		*all_eat;
	sem_t		*end;
}	t_info;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	int			eat_finish;
	long long	time_check;
	t_info		*info;
	t_th		monitoring;
	pid_t		pid;
}	t_philo;

typedef struct s_table
{
	t_info	*info;
	t_philo	*philos;
}	t_table;

int			ft_strlen(char *s);
int			ft_atoi(const char *str);

void		print_err(char *errmessage);
void		philo_print(char *msg, t_info *info, int philo_id);

int			check_arg(int argc, char **argv);
void		check_eat(t_philo *philo);
void		*ft_monitoring(void *temp);

void		init_forks(t_table *table);
void		init_philo(t_table *table);
void		init_info(t_table *table, int argc, char **argv);

long long	ft_get_time(void);
void		check_time(t_info *info, int mode);

int			philo_even(t_info *info, t_philo *philo);
int			philo_odd(t_info *info, t_philo *philo);

void		routine(t_philo *philo);
void		close_free(t_table *table);
void		destroy_philo(t_table *table);
void		philosophers(t_table *table);

#endif
