SRCS_FILES = algo_bf.c algo_custom_sort5.c algo_custom_sort6.c algo_for3.c array_test.c\
			custom_is.c destroy_and_exit.c get_input.c instruction_set.c instruction_set2.c\
			instruction_set3.c push_swap.c secure_atoi.c utils_cost.c utils_max_loop.c\
			utils_sort.c utils_sort2.c utils_sort3.c utils_sort4.c utils_sort5.c\
			utils_sort6.c utils_print.c utils_print2.c utils_checker.c\

CHECKER_FILES = array_test.c\
			destroy_and_exit.c get_input.c instruction_set.c instruction_set2.c\
			instruction_set3.c checker.c secure_atoi.c \
			utils_checker.c get_next_line.c utils_sort2.c

SRCS_DIR = ./srcs/push_swap/
CHECKER_DIR = ./srcs/checker/

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_FILES}}
CHECKER_SRCS = ${addprefix ${CHECKER_DIR}, ${CHECKER_FILES}}

OBJS = ${SRCS:.c=.o}
CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}

HEADER = ./includes/push_swap.h

INCLUDES = -I ./includes

NAME = push_swap

CHECKER = checker

CC = cc

#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ./libft
	make bonus -C ./libft
	${CC} ${CFLAGS} ${OBJS} -L ./libft -lft -o ${NAME}

${CHECKER} : ${CHECKER_OBJS} ${HEADER}
	make -C ./libft
	make bonus -C ./libft
	${CC} ${CFLAGS} ${CHECKER_OBJS} -L ./libft -lft -o ${CHECKER}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS} ${CHECKER_OBJS}
	make clean -C ./libft

fclean : clean
	rm -rf ${NAME} ${CHECKER}
	rm -rf ./libft/libft.a

re : fclean all

.PHONY:  clean fclean re all
#To fully check leaks : valgrind --leak-check=full --show-leak-kinds=all
#OLD_SRCS_FILES = get_input.c instruction_set.c secure_atoi.c destroy_and_exit.c array_test.c\
			 utils_print.c instruction_set2.c instruction_set3.c utils_sort.c custom_is.c\
			 custom_is2.c push_swap.c utils_sort2.c algo_qsort.c utils_sort3.c algo_for3.c\
			 algo_custom_sort.c algo_low.c utils_sort4.c algo_custom_sort2.c utils_checker.c\
			 algo_custom_sort3.c utils_sort5.c algo_custom_sort4.c algo_custom_sort5.c\
			 algo_custom_sort6.c algo_bf.c utils_sort6.c utils_max_loop.c utils_cost.c\
			 utils_print2.c

