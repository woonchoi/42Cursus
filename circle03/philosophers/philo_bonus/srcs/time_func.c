/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:27:10 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/08 20:57:04 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

long long	ft_get_time(void)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

void	check_time(t_info *info, int mode)
{
	long long	duration;
	long long	time_start;
	long long	time_cur;

	duration = 0;
	if (mode == 1)
		duration = info->time_to_eat;
	else if (mode == 2)
		duration = info->time_to_sleep;
	time_start = ft_get_time();
	while (1)
	{
		time_cur = ft_get_time();
		if (time_cur - time_start >= duration)
			break ;
		usleep(750);
	}
}
