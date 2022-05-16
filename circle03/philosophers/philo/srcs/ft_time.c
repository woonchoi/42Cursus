/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:02:04 by woonchoi          #+#    #+#             */
/*   Updated: 2022/05/07 14:19:49 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

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
	long long	temp;

	duration = 0;
	if (mode == 1)
		duration = info->time_to_eat;
	else if (mode == 2)
		duration = info->time_to_sleep;
	temp = duration * 1000 / 2;
	time_start = ft_get_time();
	while (!(info->finish))
	{
		time_cur = ft_get_time();
		if (time_cur - time_start >= duration)
			return ;
		usleep(temp);
		// if (temp > 500)
			temp /= 2;
	}
}