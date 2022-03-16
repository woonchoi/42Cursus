/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:46:31 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:54:31 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_info *info, int flag)
{
	int		n;

	if (pop_front(&info->top_a, &info->bot_a, &n))
	{
		push_back(n, &info->top_a, &info->bot_a);
		if (flag == TRUE)
			ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_info *info, int flag)
{
	int		n;

	if (pop_front(&info->top_b, &info->bot_b, &n))
	{
		push_back(n, &info->top_b, &info->bot_b);
		if (flag == TRUE)
			ft_putendl_fd("rrb", 1);
	}
}

void	rrr(t_info *info, int flag)
{
	rra(info, FALSE);
	rrb(info, FALSE);
	if (flag == TRUE)
		ft_putendl_fd("rrr", 1);
}
