SRCS_FILES = get_input.c instruction_set.c secure_atoi.c destroy_and_exit.c array_test.c\
			 utils_stack.c instruction_set2.c instruction_set3.c

SRCS_DIR = ./srcs/

SRCS= ${addprefix ${SRCS_DIR}, ${SRCS_FILES}}

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/push_swap.h

INCLUDES = -I ./includes

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ./libft
	make bonus -C ./libft
	${CC} ${CFLAGS} ${OBJS} -L ./libft -lft -o ${NAME}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS}
	make clean -C ./libft

fclean : clean
	rm -rf ${NAME}
	rm -rf ./libft/libft.a

re : fclean all

.PHONY:  clean fclean re all 
#To fully check leaks : valgrind --leak-check=full --show-leak-kinds=all
