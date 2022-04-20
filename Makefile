# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:43:16 by shogura           #+#    #+#              #
#    Updated: 2022/04/20 11:38:20 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=a.out

CC=gcc

CFLAG= -Wall -Wextra -Werror

NR=norminette -R CheckForbiddenSourceHeader

SRCS=get_next_line.c get_next_line_utils.c main.c

BONUS=get_next_line_bonus.c get_next_line_utils_bonus.c main.c

all:${SRCS}
	${CC} ${CFLAG} -D BUFFER_SIZE=42 $^

bonus:${BONUS}
	${CC} ${CFLAG}  -D BUFFER_SIZE=42 $^

nr:${SRCS}
	${NR} $^

fclean:
	rm -f ${NAME}

re: fclean all
