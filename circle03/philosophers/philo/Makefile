# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 22:05:51 by woonchoi          #+#    #+#              #
#    Updated: 2022/03/09 16:12:10 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	./srcs/

SRCS	=	arg_check.c\
			ft_atoi.c\
			ft_strlen.c\
			ft_time.c\
			ft_util.c\
			init_all.c\
			philo_eat.c\
			philosophers.c\
			routine.c\
			main.c\

OBJ_DIR	=	./objs/
OBJS	=	$(SRCS:.c=.o)

SRC_DIRS	=	$(addprefix $(SRC_DIR), $(SRCS))
OBJ_DIRS	=	$(addprefix $(OBJ_DIR), $(OBJS))

PHILO	=	philo
PHILO_BONUS		=	philo_bonus
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM 		=	rm -f
MKDIR	=	@mkdir -p
INCLUDE	=	-I ./inc

all: $(PHILO)

clean:
	$(RM) $(OBJ_DIRS)

fclean: clean
	$(RM) $(PHILO)

re: fclean all

$(PHILO): $(OBJ_DIRS)
	$(CC) $(CFLAGS) -o $(PHILO) $(OBJ_DIRS) -lpthread

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re bonus
