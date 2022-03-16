/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:17:16 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:12:44 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/so_long.h"

void	put_image(t_info *info, void *image, int x, int y)
{
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
		image, x * TILE_SIZE, y * TILE_SIZE);
}

void	put_image_pos(t_info *info, void *image, int x, int y)
{
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
		image, x, y);
}

void	draw_point(t_info *info, int x, int y)
{
	int		frame;

	frame = info->frame.frame / 20;
	if (info->game.map[y][x] == '1')
		wall_draw(info, x, y);
	else if (info->game.map[y][x] == '0')
		put_image(info, info->asset.floor, x, y);
	else if (info->game.map[y][x] == 'E')
		put_image(info, info->asset.flag[frame], x, y);
	else if (info->game.map[y][x] == 'C')
		put_image(info, info->asset.star[frame], x, y);
}

void	map_draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map_info.height)
	{
		x = 0;
		while (x < info->map_info.width)
		{
			draw_point(info, x, y);
			if (x == 1 && y == 0)
				draw_count(info);
			x++;
		}
		y++;
	}
}
