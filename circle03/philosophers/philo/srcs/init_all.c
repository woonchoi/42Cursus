/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:25:57 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:12:45 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	init_fork(t_info *info)
{
	int	num;
	int	i;

	num = info->philo_num;
	info->forks_arr = (int *)malloc(sizeof(int) * num);
	if (!info->forks_arr)
		return (ERROR);
	i = -1;
	while (++i < num)
		info->forks_arr[i] = FALSE;
	info->forks = (t_mu *)malloc(sizeof(t_mu) * num);
	if (!info->forks)
		return (ERROR);
	i = -1;
	while (++i < num)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (ERROR);
	}
	return (TRUE);
}

static int	init_mutex(t_info *info)
{
	if (pthread_mutex_init(&info->print, NULL)
		|| pthread_mutex_init(&info->eating, NULL)
		|| pthread_mutex_init(&info->waiting, NULL)
		|| !init_fork(info))
		return (ERROR);
	return (TRUE);
}

static int	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * (table->info.philo_num));
	if (!table->philos)
		return (ERROR);
	i = -1;
	while (++i < table->info.philo_num)
	{
		table->philos[i].id = i;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % table->info.philo_num;
		table->philos[i].eat_count = 0;
		table->philos[i].info = &table->info;
		table->philos[i].time_check = 0;
	}
	return (TRUE);
}

void	free_all(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&table->info.print);
	pthread_mutex_destroy(&table->info.eating);
	pthread_mutex_destroy(&table->info.waiting);
	if (table->info.forks_arr)
		free(table->info.forks_arr);
	if (table->info.forks)
	{
		while (++i < table->info.philo_num)
			pthread_mutex_destroy(&(table->info.forks[i]));
		free(table->info.forks);
	}
	if (table->philos)
		free(table->philos);
}

int	init_all(t_table *table)
{
	t_info	*info;

	info = &table->info;
	table->philos = NULL;
	info->forks = NULL;
	info->forks_arr = NULL;
	if (!init_mutex(info))
		return (print_err("initialize mutex failed\n"));
	if (!init_philos(table))
		return (print_err("initialize philo failed\n"));
	return (TRUE);
}
