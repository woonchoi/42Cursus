/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:27 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:14:48 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	check_eat(t_table *table)
{
	int	i;

	i = 0;
	if (table->info.must_eat_count)
	{
		while (i < table->info.philo_num
			&& table->philos[i].eat_count >= table->info.must_eat_count)
			i++;
		if (i == table->info.philo_num)
			table->info.eat_finish = 1;
	}
}

static void	ft_monitoring(t_table *table)
{
	int		i;
	t_philo	*cur;

	usleep(1000);
	while (!table->info.eat_finish)
	{
		i = 0;
		while (i < table->info.philo_num && !(table->info.finish))
		{
			pthread_mutex_lock(&(table->info.eating));
			cur = &(table->philos[i]);
			if (ft_get_time() - cur->time_check > table->info.time_to_die)
			{
				philo_print(DIE, &table->info, i);
				table->info.finish = 1;
			}
			pthread_mutex_unlock(&(table->info.eating));
			i++;
		}
		if (table->info.finish)
			break ;
		check_eat(table);
	}
}

static void	destroy_philo(t_table *table, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_join(table->philos[j].thread_id, NULL);
		j++;
	}
	j = 0;
	while (j < i)
		pthread_mutex_destroy(&(table->info.forks[j++]));
	pthread_mutex_destroy(&(table->info.print));
	pthread_mutex_destroy(&(table->info.eating));
	pthread_mutex_destroy(&(table->info.waiting));
	free(table->info.forks);
	free(table->info.forks_arr);
	free(table->philos);
}

void	philosophers(t_table *table)
{
	int		i;
	void	*temp;

	pthread_mutex_lock(&(table->info.waiting));
	i = 0;
	while (i < table->info.philo_num)
	{
		temp = (void *)&table->philos[i];
		if (pthread_create(&(table->philos[i].thread_id), NULL, routine, temp))
		{
			table->info.err = TRUE;
			print_err("pthread_create failed\n");
			break ;
		}
		i++;
	}
	table->info.start_time = ft_get_time();
	pthread_mutex_unlock(&(table->info.waiting));
	if (!table->info.err)
		ft_monitoring(table);
	destroy_philo(table, i);
}
