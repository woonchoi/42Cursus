/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:00:03 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 00:58:51 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	close_free(t_table *table)
{
	sem_close(table->info->forks);
	sem_close(table->info->print);
	sem_close(table->info->eating);
	sem_close(table->info->ready);
	sem_close(table->info->all_eat);
	sem_close(table->info->end);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eating");
	sem_unlink("/ready");
	sem_unlink("/all_eat");
	sem_unlink("/end");
	free(table->philos);
	free(table->info);
}

void	check_routine(void *table_copy)
{
	t_table	*table;
	int		i;

	table = (t_table *)table_copy;
	usleep(1000);
	i = 0;
	while (i < table->info->philo_num)
	{
		sem_wait(table->info->all_eat);
		i++;
	}
	sem_post(table->info->end);
	sem_wait(table->info->print);
	exit(1);
}

void	fork_monitoring(t_table *table)
{
	table->info->check_pid = fork();
	if (table->info->check_pid < 0)
		print_err("fork_failed\n");
	if (table->info->check_pid == 0)
		check_routine(table);
}

void	philosophers(t_table *table)
{
	int		i;
	t_philo	*philo;

	table->info->start_time = ft_get_time();
	philo = table->philos;
	sem_wait(table->info->ready);
	i = 0;
	while (i < table->info->philo_num)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			print_err("fork failed\n");
		if (philo[i].pid == 0)
			routine(&philo[i]);
		i++;
	}
	sem_post(table->info->ready);
	fork_monitoring(table);
	destroy_philo(table);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		print_err("check arguments\n");
	init_info(&table, argc, argv);
	if (table.info->philo_num < 1)
		print_err("check arguments\n");
	philosophers(&table);
	return (0);
}
