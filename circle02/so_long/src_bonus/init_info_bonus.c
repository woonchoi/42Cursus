/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:53:18 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 09:24:42 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	init_parse(t_parse *parse)
{
	parse->top = NULL;
	parse->bot = NULL;
	parse->width = 0;
	parse->height = 0;
	parse->exit_pos = 0;
	parse->s_pos = 0;
}

void	set_direc_array(t_info *info)
{
	info->dy[0] = -1;
	info->dy[1] = 0;
	info->dy[2] = 1;
	info->dy[3] = 0;
	info->dx[0] = 0;
	info->dx[1] = -1;
	info->dx[2] = 0;
	info->dx[3] = 1;
}

void	set_info(t_info *info)
{
	info->mlx_ptr = NULL;
	info->win_ptr = NULL;
	info->collect = 0;
	info->frame.frame = 0;
	info->frame.move_status = FALSE;
	info->frame.offset = 0;
	info->frame.direc = -1;
	set_direc_array(info);
}

void	init_info(t_info *info, char *file)
{
	int	fd;

	set_info(info);
	fd = open_map(file);
	read_map(info, fd);
	init_game(info);
	init_mlx(info);
	init_image(info);
}
