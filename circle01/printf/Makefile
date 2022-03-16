# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 12:23:58 by woonchoi          #+#    #+#              #
#    Updated: 2021/10/08 13:21:59 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_print_utils.c \
			ft_print_number_kind.c \
			ft_print_char_str.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a
RM		=	rm -f
LIB		=	ar rcu
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJS)
			$(LIB) $@ $^

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

bonus	:	all
