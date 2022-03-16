/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:16:46 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:54:48 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_array(t_info *info)
{
	t_deque	*temp;
	int		i;

	info->arr = (int *)malloc(sizeof(int) * info->size_a + 1);
	temp = info->bot_a;
	i = 0;
	while (temp)
	{
		info->arr[i] = temp->num;
		temp = temp->next;
		i++;
	}
}

void	init_m_info(int left, int right, int end, t_merge *m_info)
{
	m_info->b = (int *)malloc(sizeof(int) * (end + 1));
	m_info->left_index = left;
	m_info->right_index = right + 1;
	m_info->b_index = 0;
}

void	merge(int *a, int left, int right, int end)
{
	t_merge	m_info;

	init_m_info(left, right, end, &m_info);
	while (m_info.left_index <= right && m_info.right_index <= end)
	{
		if (a[m_info.left_index] >= a[m_info.right_index])
			m_info.b[m_info.b_index++] = a[m_info.left_index++];
		else
			m_info.b[m_info.b_index++] = a[m_info.right_index++];
	}
	while (m_info.left_index <= right)
		m_info.b[m_info.b_index++] = a[m_info.left_index++];
	while (m_info.right_index <= end)
		m_info.b[m_info.b_index++] = a[m_info.right_index++];
	m_info.b_index--;
	while (m_info.b_index >= 0)
	{
		a[left + m_info.b_index] = m_info.b[m_info.b_index];
		m_info.b_index--;
	}
	free(m_info.b);
	m_info.b = NULL;
}

void	merge_sort(int *a, int start, int end)
{
	int	right;

	if (start < end)
	{
		right = (start + end) / 2;
		merge_sort(a, start, right);
		merge_sort(a, right + 1, end);
		merge(a, start, right, end);
	}
}

void	preprocessing(t_info *info)
{
	int	i;

	make_array(info);
	merge_sort(info->arr, 0, info->size_a - 1);
	i = 1;
	while (i < info->size_a)
	{
		if (info->arr[i] == info->arr[i - 1])
			print_error(1);
		i++;
	}
}
