/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:34:20 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:11:33 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_collision(t_info *info, int x, int y)
{
	if (info->game.map[y][x] == '1')
		return (TRUE);
	else if (info->game.map[y][x] == 'E' && info->game.collect)
		return (TRUE);
	return (FALSE);
}

static void	draw_on_move(t_info *info)
{
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	map_draw(info);
	player_draw(info);
}

void	move(t_info *info, int direc)
{
	int	nx;
	int	ny;

	nx = info->game.p_xpos + info->dx[direc];
	ny = info->game.p_ypos + info->dy[direc];
	if (!is_collision(info, nx, ny))
	{
		info->game.map[info->game.p_ypos][info->game.p_xpos] = '0';
		if (info->game.map[ny][nx] == 'C')
			info->game.collect--;
		info->game.map[ny][nx] = 'P';
		put_image(info, info->asset.floor,
			info->game.p_xpos, info->game.p_ypos);
		info->game.p_xpos = nx;
		info->game.p_ypos = ny;
		info->game.move_count++;
		printf("step : %d\n", info->game.move_count);
		if (info->map_info.map[ny][nx] == 'E')
			info->game_status = FALSE;
		draw_on_move(info);
	}
}

void	move_direc(t_info *info, int direc)
{
	if (info->frame.direc != direc)
	{
		info->frame.direc = direc;
		info->game.current_direc = direc;
		info->frame.offset = info->frame.frame;
		info->frame.move_status = TRUE;
	}
}
