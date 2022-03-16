/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:59:16 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:17:54 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	waiting_other_philos(t_info *info)
{
	pthread_mutex_lock(&(info->waiting));
	pthread_mutex_unlock(&(info->waiting));
	if (info->err)
		return (ERROR);
	return (TRUE);
}

void	*routine(void *philo)
{
	t_info	*info;
	t_philo	*cur;

	cur = (t_philo *)philo;
	info = cur->info;
	if (!waiting_other_philos(info))
		return (NULL);
	cur->time_check = ft_get_time();
	if (cur->id % 2)
		usleep(10000);
	while (!info->finish && !info->eat_finish)
	{
		if (philo_eat(info, cur))
			break ;
		philo_print(SLEEP, info, cur->id);
		check_time(info, 2);
		philo_print(THINK, info, cur->id);
		usleep(100);
	}
	return (NULL);
}
