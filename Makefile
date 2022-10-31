# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 09:41:19 by tbouvera          #+#    #+#              #
#    Updated: 2022/10/31 12:23:01 by tbouvera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ./src/ft_printf.c ./src/ft_printf_utils.c


OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all : ${NAME}

${NAME} : ${OBJS}
	${MAKE} bonus -C ./libft 
	cp ./libft/libft.a ${NAME}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	make fclean -C ./libft

fclean: clean
	${RM} ${NAME}

re: fclean all