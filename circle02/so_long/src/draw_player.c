/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:55:00 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:15:39 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	player_draw(t_info *info)
{
	int		d;
	int		mc;
	int		frame;

	d = info->game.current_direc;
	mc = info->game.move_count % 4;
	frame = info->frame.frame / 20;
	if ((info->game_status == FALSE && info->game.move_count == 0)
		|| info->game_status == TRUE)
		put_image(info, info->asset.baba[d][mc][frame],
			info->game.p_xpos, info->game.p_ypos);
	else if (info->game_status == FALSE && info->game.move_count)
	{
		if (info->map_info.map[info->game.p_ypos][info->game.p_xpos] == 'E')
			put_image(info, info->asset.baba_end[frame],
				info->game.p_xpos, info->game.p_ypos);
	}
}
