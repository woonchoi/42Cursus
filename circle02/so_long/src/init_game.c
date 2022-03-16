/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:31:53 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:30:35 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	reset_game(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map_info.height)
	{
		x = 0;
		while (x < info->map_info.width)
		{
			info->game.map[y][x] = info->map_info.map[y][x];
			if (info->game.map[y][x] == 'P')
			{
				info->game.p_xpos = x;
				info->game.p_ypos = y;
			}
			x++;
		}
		y++;
	}
	info->game.collect = info->collect;
	info->game.move_count = 0;
	info->game_status = FALSE;
	info->game.current_direc = EAST;
	info->frame.frame = 0;
	printf("step : %d\n", info->game.move_count);
}

void	init_game(t_info *info)
{
	int		y;
	int		h;
	int		w;

	h = info->map_info.height;
	w = info->map_info.width;
	info->game.map = (char **)malloc(sizeof(char *) * (h + 1));
	if (!(info->game.map))
		print_err("Initialize map error");
	info->game.map[h] = NULL;
	y = 0;
	while (y < h)
	{
		info->game.map[y] = (char *)malloc(sizeof(char) * (w + 1));
		if (!(info->game.map[y]))
			print_err("Initialize map error");
		info->game.map[y][w] = 0;
		y++;
	}
	reset_game(info);
}
