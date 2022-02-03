NAME = philo

FLAGS = -Wall -Wextra -Werror

SRCS = philo.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc $(FLAGS) $(OBJS) -Llibft -lft -o $@

%.o : %.c
	gcc $(FLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all