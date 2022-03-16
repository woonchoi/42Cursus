/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_type_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:31:41 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 09:24:52 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

static int	check_wall(t_info *info, int x, int y)
{
	int	ret;

	ret = 0;
	if (0 <= y - 1 && info->map_info.map[y - 1][x] == '1')
		ret |= 2;
	if (0 <= x - 1 && info->map_info.map[y][x - 1] == '1')
		ret |= 4;
	if (x + 1 < info->map_info.width && info->map_info.map[y][x + 1] == '1')
		ret |= 1;
	if (y + 1 < info->map_info.height && info->map_info.map[y + 1][x] == '1')
		ret |= 8;
	return (ret);
}

static void	set_wall_type(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map_info.height)
	{
		x = 0;
		while (x < info->map_info.width)
		{
			if (info->map_info.map[y][x] == '1')
				info->asset.wall_type[y][x] = check_wall(info, x, y);
			x++;
		}
		y++;
	}
}

void	init_wall_type(t_info *info)
{
	int	i;

	info->asset.wall_type = (int **)malloc(
			sizeof(int *) * info->map_info.height);
	if (!info->asset.wall_type)
		print_err("map init fail");
	i = 0;
	while (i < info->map_info.height)
	{
		info->asset.wall_type[i] = (int *)malloc(
				sizeof(int) * info->map_info.width);
		if (!info->asset.wall_type[i])
			print_err("map init fail");
		i++;
	}
	set_wall_type(info);
}
