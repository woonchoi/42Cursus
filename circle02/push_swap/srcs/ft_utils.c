/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:26:51 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:54:09 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted(t_info *info)
{
	t_deque	*temp;
	int		i;

	temp = info->bot_a;
	i = 0;
	while (temp && i < info->size_a)
	{
		if (info->arr[i] != temp->num)
			return (FALSE);
		i++;
		temp = temp->next;
	}
	return (TRUE);
}

void	init_info(t_info *info)
{
	info->top_a = NULL;
	info->bot_a = NULL;
	info->top_b = NULL;
	info->bot_b = NULL;
	info->size_a = 0;
	info->size_b = 0;
}
