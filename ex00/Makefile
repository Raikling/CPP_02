NAME = ex00
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf


all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: clean fclean re all