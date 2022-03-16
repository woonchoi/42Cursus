# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 10:01:59 by woonchoi          #+#    #+#              #
#    Updated: 2022/02/15 01:59:14 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	./srcs/
PS_SRCS	=	ft_atoll.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_putendl.c\
			ft_split.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_p.c\
			ft_r.c\
			ft_rr.c\
			ft_s.c\
			ft_sort.c\
			ft_rotate_util.c\
			ft_rotate.c\
			ft_deque.c\
			ft_free.c\
			ft_parsing.c\
			ft_preprocessing.c\
			ft_utils.c\
			push_swap.c\

CH_SRCS	=	ft_atoll.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_putendl.c\
			ft_split.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_p.c\
			ft_r.c\
			ft_rr.c\
			ft_s.c\
			get_next_line.c\
			get_next_line_utils.c\
			ft_deque.c\
			ft_free.c\
			ft_parsing.c\
			ft_preprocessing.c\
			ft_utils.c\
			checker.c\

OBJ_DIR	=	./objs/
PS_OBJS	=	$(PS_SRCS:.c=.o)
CH_OBJS	=	$(CH_SRCS:.c=.o)

P_PS_SRCS	=	$(addprefix $(SRC_DIR), $(PS_SRCS))
P_PS_OBJS	=	$(addprefix $(OBJ_DIR), $(PS_OBJS))

P_CH_SRCS	=	$(addprefix $(SRC_DIR), $(CH_SRCS))
P_CH_OBJS	=	$(addprefix $(OBJ_DIR), $(CH_OBJS))

PUSH_SWAP	=	push_swap
CHECKER		=	checker
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f
MKDIR	=	@mkdir -p
INCLUDE	=	-I ./includes

all: $(PUSH_SWAP) $(CHECKER)

clean:
	$(RM) $(P_PS_OBJS) $(P_CH_OBJS)

fclean: clean
	$(RM) $(PUSH_SWAP) $(CHECKER)

re: fclean all

$(PUSH_SWAP): $(P_PS_OBJS)
	$(CC) $(CFLAG) -o $(PUSH_SWAP) $(P_PS_OBJS)

$(CHECKER): $(P_CH_OBJS)
	$(CC) $(CFLAG) -o $(CHECKER) $(P_CH_OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re bonus