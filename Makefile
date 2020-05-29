# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmarowak <qmarowak@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 23:15:00 by qmarowak          #+#    #+#              #
#    Updated: 2020/05/28 08:46:45 by qmarowak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	gcc -Wall -Wextra -Werror -D BUF_SIZE=1 get_next_line.c get_next_line_utils.c -I . -o main
	./main
v: 
	valgrind ./main
d:
	gcc -g -D BUF_SIZE=20 get_next_line.c get_next_line_utils.c
c:
	rm main a.out