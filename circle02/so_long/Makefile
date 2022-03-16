# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 09:35:28 by woonchoi          #+#    #+#              #
#    Updated: 2022/02/25 12:45:48 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

INCS_DIR	= ./inc/
MLX_DIR		= ./mlx/
INCS_BONUS_DIR	= ./include_bonus/

INCS		= -I include
MLX_FLAGS	= -L ./mlx -lmlx -framework OpenGL -framework Appkit
MLX_FLAGS_LINUX	= -L ./mlx -lmlx -lXext -lX11

SRCS =   src/main.c				\
		src/ft_strlen.c			\
		src/ft_putendl_fd.c		\
		src/ft_strncmp.c		\
		src/ft_strjoin.c		\
		src/hook.c				\
		src/init_game.c			\
		src/init_info.c			\
		src/init_mlx.c			\
		src/key_release.c		\
		src/main_loop.c			\
		src/move.c				\
		src/parse_map.c			\
		src/set_map.c			\
		src/draw_map.c			\
		src/draw_player.c		\
		src/draw_count.c		\
		src/draw_wall.c			\
		src/init_image.c		\
		src/init_player_image.c	\
		src/init_wall_image.c	\
		src/init_count_image.c	\
		src/init_wall_type.c	\
        gnl/get_next_line.c         \
        gnl/get_next_line_utils.c   \

SRCS_BONUS	=	src_bonus/main_bonus.c			\
		src_bonus/ft_strlen_bonus.c			\
		src_bonus/ft_putendl_fd_bonus.c		\
		src_bonus/ft_strncmp_bonus.c		\
		src_bonus/ft_strjoin_bonus.c		\
		src_bonus/hook_bonus.c				\
		src_bonus/init_game_bonus.c			\
		src_bonus/init_info_bonus.c			\
		src_bonus/init_mlx_bonus.c			\
		src_bonus/key_release_bonus.c		\
		src_bonus/main_loop_bonus.c			\
		src_bonus/move_bonus.c				\
		src_bonus/parse_map_bonus.c			\
		src_bonus/set_map_bonus.c			\
		src_bonus/draw_map_bonus.c			\
		src_bonus/draw_player_bonus.c		\
		src_bonus/draw_count_bonus.c		\
		src_bonus/draw_wall_bonus.c			\
		src_bonus/init_image_bonus.c		\
		src_bonus/init_player_image_bonus.c	\
		src_bonus/init_wall_image_bonus.c	\
		src_bonus/init_count_image_bonus.c	\
		src_bonus/init_wall_type_bonus.c	\
        gnl_bonus/get_next_line_bonus.c         \
        gnl_bonus/get_next_line_utils_bonus.c   \

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR) $(MLX_FLAGS)

all : $(NAME)

clean :
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : clean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) -I $(INCS_BONUS_DIR) $(MLX_FLAGS)
PHONY	: all clean fclean re bonus
