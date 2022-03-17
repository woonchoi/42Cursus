SRCS = ./megaphone.cpp

CC = clang++
NAME = megaphone

CFLAG = -Wall -Werror -Wextra
CPPVER = -std=c++98

RM = rm -f

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(CPPVER) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re