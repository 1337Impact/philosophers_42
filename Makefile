NAME = philo
FLAGS = -Wall -Wextra -Werror

SRCS = philo.c utils.c check_params.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc $(FLAGS) $(OBJS) -lpthread -o $@

%.o : %.c
	gcc $(FLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : all clean
	echo "---------------------------------------" && ./philo 4 410 200 100
