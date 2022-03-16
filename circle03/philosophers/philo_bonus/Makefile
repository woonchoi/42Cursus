# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 22:05:51 by woonchoi          #+#    #+#              #
#    Updated: 2022/03/06 16:17:49 by woonchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	./srcs/

SRCS	=	ft_atoi.c\
			ft_routine.c\
			ft_strlen.c\
			ft_util.c\
			init_func.c\
			philosophers.c\
			time_func.c\
			destroy_philo.c\

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

all: $(PHILO_BONUS)

clean:
	$(RM) $(OBJ_DIRS)

fclean: clean
	$(RM) $(PHILO_BONUS)

re: fclean all

$(PHILO_BONUS): $(OBJ_DIRS)
	$(CC) $(CFLAGS) -o $(PHILO_BONUS) $(OBJ_DIRS) -lpthread

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re bonus
