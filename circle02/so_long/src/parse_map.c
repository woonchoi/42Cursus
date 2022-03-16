/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:23:36 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/23 17:52:17 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	open_map(char *file)
{
	int	fd;
	int	file_len;

	file_len = ft_strlen(file);
	if (file_len < 5)
		print_err("File name error");
	if (ft_strncmp(file + file_len - 4, ".ber", 4))
		print_err("File extension is not .ber");
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		print_err("An error occurred while reading mapfile");
	return (fd);
}

t_mapline	*make_new_mapline(char *line)
{
	t_mapline	*mapline;

	mapline = (t_mapline *)malloc(sizeof(t_mapline));
	mapline->line = line;
	mapline->next = NULL;
	return (mapline);
}

void	mapline_addback(t_parse *parse, char *line)
{
	int		line_len;

	line_len = ft_strlen(line);
	if (parse->height == 0)
	{
		parse->top = make_new_mapline(line);
		parse->bot = parse->top;
		parse->width = line_len - 1;
		if (parse->width == 0)
			print_err("Invalid map file");
		parse->height++;
	}
	else
	{
		if (line[line_len - 1] != '\n')
			line_len += 1;
		if (line_len - 1 != parse->width)
			print_err("Map file is not rectangular");
		parse->bot->next = make_new_mapline(line);
		parse->bot = parse->bot->next;
		parse->height++;
	}
}

void	free_parse_list(t_parse *parse)
{
	t_mapline	*temp;
	t_mapline	*cur;

	temp = parse->top;
	while (temp)
	{
		cur = temp->next;
		free(temp->line);
		temp->line = NULL;
		free(temp);
		temp = cur;
	}
	parse->top = NULL;
	parse->bot = NULL;
}

void	read_map(t_info *info, int fd)
{
	t_parse		parse;
	char		*mapline;

	init_parse(&parse);
	mapline = get_next_line(fd);
	if (mapline == NULL)
		print_err("Mapfile is empty");
	while (mapline)
	{
		mapline_addback(&parse, mapline);
		mapline = get_next_line(fd);
	}
	set_map_array(info, &parse);
	if (parse.exit_pos == 0 || parse.s_pos == 0
		|| info->game.collect == 0)
		print_err("Mapfile is not valid");
	free_parse_list(&parse);
}
