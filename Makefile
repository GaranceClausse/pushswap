# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:46:56 by gclausse          #+#    #+#              #
#    Updated: 2022/02/03 13:55:12 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= push_swap.c \
     swap_utils_a.c \
     swap_utils_b.c \
     place_num.c \
     check_input.c \
	 divide_stack.c \
	 get_index.c \
	 sort_stack.c

LIBFT_PATH= libft

LIBFT_NAME= ${LIBFT_PATH}/libft.a

NAME= push_swap

CC= gcc 

CFLAGS= -Wall -Werror -Wextra -I${LIBFT_PATH}

OBJ= ${SRC:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 
	
all: ${NAME}
		
${NAME}: ${OBJ}
		make -C ${LIBFT_PATH}
		${CC} ${OBJ} ${LIBFT_NAME} -o ${NAME}

clean:
	make clean -C ${LIBFT_PATH} && rm -f ${OBJ}

fclean: clean
	rm -f ${LIBFT_NAME} && rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
