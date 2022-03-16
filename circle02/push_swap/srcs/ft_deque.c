/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:39:04 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:55:03 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_deque	*create_node(int num)
{
	t_deque	*node;

	node = (t_deque *)malloc(sizeof(t_deque));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_back(int num, t_deque **top, t_deque **bot)
{
	t_deque	*node;

	node = create_node(num);
	if (node == NULL)
		return ;
	if (*top == NULL)
	{
		*bot = node;
		*top = node;
	}
	else
	{
		(*top)->next = node;
		node->prev = *top;
		*top = node;
	}
}

void	push_front(int num, t_deque **top, t_deque **bot)
{
	t_deque	*node;

	node = create_node(num);
	if (node == NULL)
		return ;
	if (*bot == NULL)
	{
		*bot = node;
		*top = node;
	}
	else
	{
		(*bot)->prev = node;
		node->next = *bot;
		*bot = node;
	}
}

int	pop_back(t_deque **top, t_deque **bot, int *num)
{	
	if (!(*top))
		return (FALSE);
	*num = (*top)->num;
	if (*top == *bot)
	{
		free_node(*top);
		*top = NULL;
		*bot = NULL;
	}
	else
	{
		*top = (*top)->prev;
		free((*top)->next);
		(*top)->next = NULL;
		if (*top == *bot)
			(*bot)->next = NULL;
	}
	return (TRUE);
}

int	pop_front(t_deque **top, t_deque **bot, int *num)
{	
	if (!(*bot))
		return (FALSE);
	*num = (*bot)->num;
	if (*top == *bot)
	{
		free_node(*bot);
		*top = NULL;
		*bot = NULL;
	}
	else
	{
		*bot = (*bot)->next;
		free((*bot)->prev);
		(*bot)->prev = NULL;
		if (*bot == *top)
			(*top)->prev = NULL;
	}
	return (TRUE);
}
