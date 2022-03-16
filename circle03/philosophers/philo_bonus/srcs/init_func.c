/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:07:52 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/08 21:26:52 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

int	check_arg(int argc, char **argv)
{
	if (argc == 6)
		return (ft_atoi(argv[5]));
	return (0);
}

void	init_forks(t_table *table)
{
	t_info	*info;

	info = table->info;
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eating");
	sem_unlink("/ready");
	sem_unlink("/all_eat");
	sem_unlink("/end");
	info->forks = sem_open("/forks", O_CREAT, 0644, info->philo_num);
	info->print = sem_open("/print", O_CREAT, 0644, 1);
	info->eating = sem_open("/eating", O_CREAT, 0644, 1);
	info->ready = sem_open("/ready", O_CREAT, 0644, 1);
	info->all_eat = sem_open("/all_eat", O_CREAT, 0644, 0);
	info->end = sem_open("/end", O_CREAT, 0644, 0);
	if (info->forks == NULL || info->print == NULL
		|| info->eating == NULL || info->ready == NULL
		|| info->all_eat == NULL)
		print_err("init semaphore failed\n");
}

void	init_philo(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * (table->info->philo_num + 1));
	if (!table->philos)
		print_err("malloc philo failed");
	i = 0;
	while (i < table->info->philo_num)
	{
		table->philos[i].id = i;
		table->philos[i].eat_count = 0;
		table->philos[i].info = table->info;
		table->philos[i].time_check = 0;
		table->philos[i].eat_finish = 0;
		i++;
	}
}

void	init_info(t_table *table, int argc, char **argv)
{
	table->info = (t_info *)malloc(sizeof(t_info));
	if (!table->info)
		print_err("initialize failed\n");
	table->info->philo_num = ft_atoi(argv[1]);
	table->info->time_to_die = ft_atoi(argv[2]);
	table->info->time_to_eat = ft_atoi(argv[3]);
	table->info->time_to_sleep = ft_atoi(argv[4]);
	table->info->must_eat_count = check_arg(argc, argv);
	init_forks(table);
	init_philo(table);
}
