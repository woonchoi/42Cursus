/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:08:18 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 12:58:21 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	wall_draw(t_info *info, int x, int y)
{
	int	type;
	int	frame;

	type = info->asset.wall_type[y][x];
	frame = info->frame.frame / 20;
	put_image(info, info->asset.wall[type][frame], x, y);
}
