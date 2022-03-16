/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:00:44 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 14:01:55 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philo_print(char *msg, t_info *info, int philo_id)
{
	pthread_mutex_lock(&(info->print));
	if (!(info->finish) && !(info->eat_finish))
	{
		printf("%lld ", ft_get_time() - info->start_time);
		printf("%d ", philo_id + 1);
		printf("%s\n", msg);
	}
	pthread_mutex_unlock(&(info->print));
}

int	print_err(char *errmessage)
{
	write(STDERR_FILENO, errmessage, ft_strlen(errmessage));
	write(STDERR_FILENO, "Error!\n", 7);
	return (ERROR);
}
