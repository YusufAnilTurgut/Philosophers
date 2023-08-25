
NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror 

SRCS = main.c ft_utils.c ft_check_controls.c\
	ft_threads_create.c ft_print.c\
	ft_routine.c ft_init.c ft_death.c

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
