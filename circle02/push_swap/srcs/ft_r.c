/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:45:42 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:54:42 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_info *info, int flag)
{
	int		n;

	if (pop_back(&info->top_a, &info->bot_a, &n))
	{
		push_front(n, &info->top_a, &info->bot_a);
		if (flag == TRUE)
			ft_putendl_fd("ra", 1);
	}
}

void	rb(t_info *info, int flag)
{
	int		n;

	if (pop_back(&info->top_b, &info->bot_b, &n))
	{
		push_front(n, &info->top_b, &info->bot_b);
		if (flag == TRUE)
			ft_putendl_fd("rb", 1);
	}
}

void	rr(t_info *info, int flag)
{
	ra(info, FALSE);
	rb(info, FALSE);
	if (flag == TRUE)
		ft_putendl_fd("rr", 1);
}
