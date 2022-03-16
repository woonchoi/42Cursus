/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:44:06 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:54:28 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_info *info, int flag)
{
	t_deque	*temp;
	int		num;

	if (info->size_a >= 2)
	{
		if (info->size_a != 2)
		{
			temp = info->top_a->prev;
			info->top_a->prev = temp->prev;
			temp->prev->next = info->top_a;
			temp->prev = info->top_a;
			temp->next = NULL;
			info->top_a->next = temp;
			info->top_a = temp;
		}
		else
		{
			pop_back(&info->top_a, &info->bot_a, &num);
			push_front(num, &info->top_a, &info->bot_a);
		}
		if (flag == TRUE)
			ft_putendl_fd("sa", 1);
	}
}

void	sb(t_info *info, int flag)
{
	t_deque	*temp;
	int		num;

	if (info->size_b >= 2)
	{
		if (info->size_b == 2)
		{
			pop_back(&info->top_b, &info->bot_b, &num);
			push_front(num, &info->top_b, &info->bot_b);
		}
		else
		{
			temp = info->top_b->prev;
			info->top_b->prev = temp->prev;
			temp->prev->next = info->top_b;
			temp->prev = info->top_b;
			temp->next = NULL;
			info->top_b->next = temp;
			info->top_b = temp;
		}
		if (flag == TRUE)
			ft_putendl_fd("sb", 1);
	}
}

void	ss(t_info *info, int flag)
{
	if (info->size_a >= 3 && info->size_b >= 3)
	{
		sa(info, FALSE);
		sb(info, FALSE);
		if (flag == TRUE)
			ft_putendl_fd("ss", 1);
	}
}
