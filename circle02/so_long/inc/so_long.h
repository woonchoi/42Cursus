/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:40:35 by edjavid           #+#    #+#             */
/*   Updated: 2022/02/25 12:47:16 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "key.h"
# include "image.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define TILE_SIZE 48

# define NORTH 0
# define WEST 1
# define SOUTH 2
# define EAST 3

typedef struct s_view
{
	int		size_x;
	int		size_y;
}	t_view;

typedef struct s_game
{
	char	**map;
	int		collect;
	int		p_xpos;
	int		p_ypos;
	int		move_count;
	int		current_direc;
}	t_game;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_frame
{
	int	frame;
	int	direc;
	int	offset;
	int	move_status;
}	t_frame;

typedef struct s_mapline
{
	char				*line;
	struct s_mapline	*next;
}	t_mapline;

typedef struct s_parse
{
	t_mapline	*top;
	t_mapline	*bot;
	int			width;
	int			height;
	int			exit_pos;
	int			s_pos;
}	t_parse;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map_info;
	int			collect;
	t_view		screen;
	t_game		game;
	t_frame		frame;
	t_asset		asset;
	t_myimg		img;
	int			game_status;
	int			dx[4];
	int			dy[4];
}	t_info;

size_t		ft_strlen(const char *src);
void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);

void		print_err(char *errmessage);

int			key_press_hook(int key_code, t_info *info);
int			key_release_hook(int key_code, t_info *info);
int			exit_hook(t_info *info);

void		init_parse(t_parse *parse);
int			open_map(char *file);
t_mapline	*make_new_mapline(char *line);
void		mapline_addback(t_parse *parse, char *line);
void		free_parse_list(t_parse *parse);
void		read_map(t_info *info, int fd);

void		reset_game(t_info *info);
void		init_game(t_info *info);

void		set_direc_array(t_info *info);
void		set_info(t_info *info);
void		init_info(t_info *info, char *file);

void		init_mlx(t_info *info);

void		release_key(t_info *info, int direc);

void		frame_count(t_info *info);
void		move_check(t_info *info);
int			game_loop(t_info *info);

int			is_collision(t_info *info, int x, int y);
void		move(t_info *info, int direc);
void		move_direc(t_info *info, int direc);

void		malloc_map_array(t_info *info, t_parse *parse);
void		count_element(t_parse *parse, t_info *info, char c);
void		set_map_array(t_info *info, t_parse *parse);

void		*ft_xpm_to_img(t_info *info, char *file, char *img_path);

void		init_player_image(t_info *info);
void		init_wall_image(t_info *info);
void		init_wall_type(t_info *info);
void		init_count_image(t_info *info);
void		init_image(t_info *info);

void		put_image(t_info *info, void *image, int x, int y);
void		put_image_pos(t_info *info, void *image, int x, int y);
void		draw_point(t_info *info, int x, int y);

void		map_draw(t_info *info);
void		player_draw(t_info *info);
void		wall_draw(t_info *info, int x, int y);
void		draw_count(t_info *info);

void		print_map(t_info *info);

#endif