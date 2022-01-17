NAME = push_swap
BONUS_NAME = checker
LIBFT = ./libft/libft.a
SRCS = $(shell find "." \! -name 'checker.c' -name "*.c")
BONUS_SRCS = $(shell find "." \! -name 'main.c' -name "*.c")
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${OBJS} ${CFLAGS} ./libft/libft.a -o ${NAME}

bonus: ${BONUS_OBJS}
	@$(MAKE) -C ./libft
	@${CC} ${BONUS_OBJS} ${CFLAGS} ./libft/libft.a -o ${BONUS_NAME}

clean :
	@${MAKE} clean -C ./libft
	@rm -rf *.o

fclean : clean
	@${MAKE} fclean -C ./libft
	@rm -rf ${NAME}
	@rm -rf ${BONUS_NAME}

re : fclean all

.PHONY : all clean fclean re .c.o
