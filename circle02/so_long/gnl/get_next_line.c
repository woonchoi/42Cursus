/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:57:05 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/16 23:10:14 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	find_newline(char *buffer)
{
	int		index;

	index = 0;
	if (!buffer)
		return (-1);
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*split_line(char **buf_memory, int new_line_index, char **buffer)
{
	char	*temp;
	char	*line;
	int		length;

	if (*buffer)
	{
		free(*buffer);
		*buffer = 0;
	}
	(*buf_memory)[new_line_index] = '\0';
	line = ft_strdup_gnl(*buf_memory);
	length = ft_strlen(*buf_memory + new_line_index + 1);
	if (!length)
	{
		free(*buf_memory);
		*buf_memory = 0;
		line[ft_strlen(line)] = '\n';
		return (line);
	}
	temp = ft_strdup_gnl(*buf_memory + new_line_index + 1);
	free(*buf_memory);
	*buf_memory = temp;
	line[ft_strlen(line)] = '\n';
	return (line);
}

char	*empty_buf(char **buf_memory, char **buffer, int read_size)
{
	int		new_line_index;
	char	*line;

	free(*buffer);
	*buffer = NULL;
	if (read_size < 0)
		return (NULL);
	new_line_index = find_newline(*buf_memory);
	if (*buf_memory && new_line_index >= 0)
		return (split_line(buf_memory, new_line_index, buffer));
	else if (*buf_memory)
	{
		line = *buf_memory;
		*buf_memory = NULL;
		return (line);
	}
	free(*buf_memory);
	*buf_memory = NULL;
	line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf_memory[OPEN_MAX + 3];
	char		*buffer;
	int			read_size;
	int			new_line_index;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		buf_memory[fd] = ft_strjoin_gnl(buf_memory[fd], buffer);
		new_line_index = find_newline(buf_memory[fd]);
		if (new_line_index >= 0)
			return (split_line(&(buf_memory[fd]), new_line_index, &buffer));
	}
	return (empty_buf(&(buf_memory[fd]), &buffer, read_size));
}
