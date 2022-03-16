/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_count_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:36:50 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:04:21 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	draw_count(t_info *info)
{
	int		i;
	int		count;
	int		p;
	int		f;

	put_image_pos(info, info->asset.count, 0, 6);
	i = 1;
	count = info->game.move_count;
	f = info->frame.frame / 20;
	p = count % 10;
	put_image_pos(info, info->asset.number[p][f], 96 - i * 18, 12);
	while (count / 10 != 0)
	{
		i++;
		if (i == 6)
			print_err("your game skill is so bad...");
		count = count / 10;
		p = count % 10;
		put_image_pos(info, info->asset.number[p][f], 96 - i * 18, 12);
	}
}
