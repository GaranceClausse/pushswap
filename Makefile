# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:46:56 by gclausse          #+#    #+#              #
#    Updated: 2021/12/03 21:10:58 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= ft_putnbr_base.c\
	 ft_putnbr_base_unsgn.c\
	 ft_putnbr_usgn_lg.c\
	 ft_printf.c

LIBFT_PATH= libft

LIBFT_NAME= libft.a

NAME= libftprintf.a

CC= gcc 

CFLAGS= -Wall -Werror -Wextra -I${LIBFT_PATH}

OBJ= ${SRC:.c=.o}

OBJBONUS= ${SRCBONUS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 
	
all: ${NAME}
		
${NAME}: ${OBJ}
		make -C $(LIBFT_PATH)
		cp ${LIBFT_PATH}/${LIBFT_NAME} $(NAME)
		ar -rc ${NAME} ${OBJ}

clean:
	make clean -C $(LIBFT_PATH) && rm -f *.o

fclean: clean
	make clean -C $(LIBFT_PATH) && rm -f ${LIBFT_PATH}/${LIBFT_NAME} && rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
