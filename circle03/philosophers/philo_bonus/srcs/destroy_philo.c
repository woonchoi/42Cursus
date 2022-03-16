/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:07:53 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/08 21:56:26 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	destroy_philo(t_table *table)
{
	int	i;

	sem_wait(table->info->end);
	i = 0;
	while (i < table->info->philo_num)
	{
		kill(table->philos[i].pid, SIGTERM);
		i++;
	}
	kill(table->info->check_pid, SIGTERM);
	close_free(table);
}
