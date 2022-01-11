NAME = push_swap
LIBFT = ./libft/libft.a
SRCS = $(shell find "." -name "*.c")
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra

AR = ar csr

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${OBJS} ${CFLAGS} ./libft/libft.a -o ${NAME}

clean :
	@${MAKE} clean -C ./libft
	@rm -rf *.o

fclean : clean
	@${MAKE} fclean -C ./libft
	@rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re .c.o
