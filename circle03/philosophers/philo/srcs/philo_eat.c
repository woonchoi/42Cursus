/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:26:19 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 15:49:33 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	get_fork(t_info *info, int fork_num, int philo_id)
{
	pthread_mutex_lock(&(info->forks[fork_num]));
	info->forks_arr[fork_num]++;
	philo_print(TAKE_FORK, info, philo_id);
}

static void	release_fork(t_info *info, int fork_num)
{
	info->forks_arr[fork_num]--;
	pthread_mutex_unlock(&(info->forks[fork_num]));
}

static void	eat_spaghetti(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->eating));
	philo_print(EAT, info, philo->id);
	philo->time_check = ft_get_time();
	pthread_mutex_unlock(&(info->eating));
	check_time(info, 1);
	philo->eat_count++;
}

int	philo_eat(t_info *info, t_philo *philo)
{
	get_fork(info, philo->left_fork, philo->id);
	if (philo->right_fork == philo->left_fork)
	{
		release_fork(info, philo->left_fork);
		return (1);
	}
	get_fork(info, philo->right_fork, philo->id);
	eat_spaghetti(info, philo);
	release_fork(info, philo->left_fork);
	release_fork(info, philo->right_fork);
	if (info->eat_finish || info->finish)
		return (1);
	return (0);
}
