/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:34:38 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/08 22:05:01 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	eat_process(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	sem_wait(info->forks);
	philo_print(TAKE_FORK, info, philo->id);
	sem_wait(info->forks);
	philo_print(TAKE_FORK, info, philo->id);
	sem_wait(info->eating);
	philo_print(EAT, info, philo->id);
	philo->time_check = ft_get_time();
	sem_post(info->eating);
	check_time(info, 1);
	philo->eat_count++;
	sem_post(info->forks);
	sem_post(info->forks);
}

void	*ft_monitoring(void *temp)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)temp;
	info = philo->info;
	while (1)
	{
		sem_wait(info->eating);
		if (ft_get_time() - philo->time_check > info->time_to_die)
		{
			sem_wait(info->print);
			printf("%lld ", ft_get_time() - info->start_time);
			printf("%d ", philo->id + 1);
			printf("died\n");
			sem_post(info->end);
			exit(1);
		}
		sem_post(info->eating);
		usleep(100);
	}
}

void	wait_for_other_philo(t_info *info)
{
	sem_wait(info->ready);
	sem_post(info->ready);
}

void	check_all_eat(t_info *info, t_philo *philo)
{
	if (info->must_eat_count && philo->eat_count >= info->must_eat_count
		&& !philo->eat_finish)
	{
		sem_post(info->all_eat);
		philo->eat_finish = 1;
	}
}

void	routine(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	philo->time_check = ft_get_time();
	pthread_create(&(philo->monitoring), NULL, ft_monitoring, (void *)philo);
	wait_for_other_philo(info);
	if (philo->id % 2)
		usleep(10000);
	while (1)
	{
		eat_process(philo);
		check_all_eat(info, philo);
		philo_print(SLEEP, info, philo->id);
		check_time(info, 2);
		philo_print(THINK, info, philo->id);
		usleep(100);
	}
}
