
NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

SRCS = main.c utils.c controls.c threads.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "Compile Completed!"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.c.o:
	@echo "$(PINK2)Complining: $<"
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
