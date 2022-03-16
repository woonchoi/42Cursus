/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:27:16 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/23 17:52:54 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	malloc_map_array(t_info *info, t_parse *parse)
{
	int	y;
	int	h;
	int	w;

	h = parse->height;
	w = parse->width;
	y = 0;
	info->map_info.map = (char **)malloc(sizeof(char *) * (h + 1));
	if (!(info->map_info.map))
		print_err("Initialize map error");
	info->map_info.map[h] = NULL;
	while (y < h)
	{
		info->map_info.map[y] = (char *)malloc(sizeof(char) * (w + 1));
		if (!(info->map_info.map[y]))
			print_err("Initialize map error");
		info->map_info.map[y][w] = 0;
		y++;
	}
	info->map_info.width = w;
	info->map_info.height = h;
}

void	count_element(t_parse *parse, t_info *info, char c)
{
	if (c == 'C')
	{
		info->game.collect++;
		info->collect++;
	}
	else if (c == 'E')
		parse->exit_pos++;
	else if (c == 'P')
	{
		parse->s_pos++;
		if (parse->s_pos > 1)
			print_err("There are more than one starting point on the map");
	}
	else if (c == '1' || c == '0')
		return ;
	else
		print_err("There are invalid characters on the map");
}

void	set_map_array(t_info *info, t_parse *parse)
{
	int			x;
	int			y;
	t_mapline	*cur;

	malloc_map_array(info, parse);
	y = 0;
	cur = parse->top;
	while (y < parse->height)
	{
		x = 0;
		while (x < parse->width)
		{
			info->map_info.map[y][x] = cur->line[x];
			if (y == 0 || y == parse->height - 1
				|| x == 0 || x == parse->width - 1)
			{
				if (info->map_info.map[y][x] != '1')
					print_err("There is no wall at the border of the map");
			}
			count_element(parse, info, info->map_info.map[y][x]);
			x++;
		}
		y++;
		cur = cur->next;
	}
}
