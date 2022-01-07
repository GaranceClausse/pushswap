# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:46:56 by gclausse          #+#    #+#              #
#    Updated: 2022/01/07 14:03:43 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= push_swap.c \
	 swap_utils_a.c \
	 swap_utils_b.c \
	 stack_management.c


LIBFT_PATH= libft

LIBFT_NAME= libft.a

NAME= push_swap.a

NAME_EXEC= push_swap

CC= gcc 

CFLAGS= -Wall -Werror -Wextra -I${LIBFT_PATH}

OBJ= ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 
	
all: ${NAME}
		
${NAME}: ${OBJ}
		make -C ${LIBFT_PATH}
		cp ${LIBFT_PATH}/${LIBFT_NAME} ${NAME}
		ar -rc ${NAME} ${OBJ}
		@${CC} ${CFLAGS} ${NAME} -o ${NAME_EXEC}

clean:
	make clean -C ${LIBFT_PATH} && rm -f *.o

fclean: clean
	make clean -C ${LIBFT_PATH} && rm -f ${LIBFT_PATH}/${LIBFT_NAME} && rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
