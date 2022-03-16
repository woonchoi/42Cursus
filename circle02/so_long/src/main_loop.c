/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:35:12 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:28:52 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	frame_count(t_info *info)
{
	info->frame.frame++;
	if (info->frame.frame >= 59)
		info->frame.frame = 0;
}

void	move_check(t_info *info)
{
	if (info->frame.frame % 20 == info->frame.offset % 20)
	{
		if (info->frame.direc != -1 && info->frame.move_status == TRUE)
		{
			if (info->game_status == TRUE)
				move(info, info->frame.direc);
		}
	}
}

int	game_loop(t_info *info)
{
	if (info->frame.frame % 20 == 0)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		map_draw(info);
	}
	move_check(info);
	player_draw(info);
	frame_count(info);
	return (0);
}
