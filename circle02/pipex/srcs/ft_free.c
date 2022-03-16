/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:55:17 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/06 23:52:38 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_vec(void **vec)
{
	int	i;

	i = 0;
	while (vec[i])
	{
		free_ptr(vec[i]);
		i++;
	}
	if (vec)
	{
		free(vec);
		vec = NULL;
	}
}

void	free_parents(t_info *info)
{
	free_vec((void **)(info->env_path));
	free_vec((void **)(info->parent.option));
	free_ptr(info->parent.cmd);
}

void	free_child(t_info *info)
{
	free_vec((void **)(info->env_path));
	free_vec((void **)(info->child.option));
	free_ptr(info->child.cmd);
}
