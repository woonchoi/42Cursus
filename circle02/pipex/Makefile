# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 10:01:59 by woonchoi          #+#    #+#              #
#    Updated: 2022/02/07 15:57:39 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	./srcs/
SRCS	=	ft_bzero.c\
			ft_calloc.c\
			ft_free.c\
			ft_memcmp.c\
			ft_parsing.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strnstr.c\
			pipex_process.c\
			pipex.c\

OBJ_DIR	=	./objs/
OBJS	=	$(SRCS:.c=.o)

P_SRCS	=	$(addprefix $(SRC_DIR), $(SRCS))
P_OBJS	=	$(addprefix $(OBJ_DIR), $(OBJS))

NAME	=	pipex
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f
MKDIR	=	@mkdir -p
INCLUDE	=	-I ./includes

all: $(NAME)

clean:
	$(RM) $(P_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(P_OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(P_OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re
