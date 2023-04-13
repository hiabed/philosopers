NAME = philo

CFILES = philosophers.c ft_atoi.c

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
