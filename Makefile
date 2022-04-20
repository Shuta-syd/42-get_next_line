# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/04/19 15:11:31 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAG=-g

NR=norminette -R CheckForbiddenSourceHeader

SRCS=get_next_line.c get_next_line_utils.c

all:${SRCS}
	${CC} ${CFLAG} -D BUFFER_SIZE=42 $^

nr:${SRCS}
	${NR} $^

fclean:
	rm -f ${NAME}

re: fclean all
