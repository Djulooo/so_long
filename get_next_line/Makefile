.PHONY:		all clean fclean re

SRCS	=	get_next_line.c	get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}

FLAGS	=	-Wall -Wextra -Werror

HEADER	=	get_next_line.h

LIB		=	${AR} rc

NAME	=	gnl.a

all:		${NAME} Makefile

%.o:		%.c ${HEADER} Makefile
			${CC} ${FLAGS} -I${HEADER} -c $< -o $@

${NAME}:	${OBJS}
			${LIB} $@ ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all