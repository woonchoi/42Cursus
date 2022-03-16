/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:33:52 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/06 19:54:15 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

void	philo_print(char *msg, t_info *info, int philo_id)
{
	sem_wait(info->print);
	printf("%lld ", ft_get_time() - info->start_time);
	printf("%d ", philo_id + 1);
	printf("%s\n", msg);
	sem_post(info->print);
}

void	print_err(char *errmessage)
{
	write(STDERR_FILENO, errmessage, ft_strlen(errmessage));
	write(STDERR_FILENO, "Error!\n", 7);
	exit(0);
}
