SRCS = main.c functions0.c functions1.c functions2.c functions3.c functions4.c
CC= cc -Wall -Wextra -Werror
RM = rm -f
NAME = bsq

${NAME} : ${SRCS}
	${CC} ${SRCS} -o ${NAME}

all : ${NAME}

fclean :
	${RM} ${NAME}

re : fclean all

.PHONY : all fclean re