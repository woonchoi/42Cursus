/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:35:37 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 02:12:32 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_between(int a, int b, int num)
{
	if (a < b)
	{
		if (b < num)
			return (TRUE);
		else if (a > num)
			return (TRUE);
	}
	else
	{
		if (b < num && num < a)
			return (TRUE);
	}
	return (FALSE);
}

void	find_pos_a(t_info *info, int num, int *a)
{
	t_deque	*temp;
	int		move;

	move = 0;
	if (is_between(info->top_a->num, info->bot_a->num, num))
	{
		*a = move;
		return ;
	}
	temp = info->top_a->prev;
	while (temp)
	{
		move++;
		if (is_between(temp->num, temp->next->num, num))
		{
			*a = move;
			return ;
		}
		temp = temp->prev;
	}
}

void	check_move_direc(t_info *info, int *a_move, int *b_move)
{
	int	rcount;
	int	rrcount;

	if (*a_move < *b_move)
		rcount = *b_move;
	else
		rcount = *a_move;
	if (info->size_a - *a_move < info->size_b - *b_move)
		rrcount = info->size_b - *b_move;
	else
		rrcount = info->size_a - *a_move;
	if (rcount > rrcount)
	{
		*a_move = -(info->size_a - *a_move);
		*b_move = -(info->size_b - *b_move);
	}
}

int	compare_move(int min_a, int min_b, int a_move, int b_move)
{
	int	min_count;
	int	temp_count;

	if (min_a < 0 || min_b < 0)
	{
		min_a *= -1;
		min_b *= -1;
	}
	if (a_move < 0 || b_move < 0)
	{
		a_move *= -1;
		b_move *= -1;
	}
	if (min_a < min_b)
		min_count = min_b;
	else
		min_count = min_a;
	if (a_move < b_move)
		temp_count = b_move;
	else
		temp_count = a_move;
	return (temp_count < min_count);
}

void	set_min_move(int *min_a, int *min_b, int a_move, int b_move)
{
	if (compare_move(*min_a, *min_b, a_move, b_move))
	{
		*min_a = a_move;
		*min_b = b_move;
	}
}
