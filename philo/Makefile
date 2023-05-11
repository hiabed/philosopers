NAME = philo

CFILES = philosophers.c ft_atoi.c mutexes.c time.c is_digit.c

OBJ = ${CFILES:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = cc

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all
