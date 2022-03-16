/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:30:02 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/23 17:51:19 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		print_err("mlx_init process fail");
	info->screen.size_x = info->map_info.width * TILE_SIZE;
	info->screen.size_y = info->map_info.height * TILE_SIZE;
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->screen.size_x, info->screen.size_y, "so_long");
	if (!info->win_ptr)
		print_err("mlx_new_window process fail");
}
