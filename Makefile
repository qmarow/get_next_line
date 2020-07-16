# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmarowak <qmarowak@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 23:15:00 by qmarowak          #+#    #+#              #
#    Updated: 2020/05/30 23:09:36 by qmarowak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c -I . -o main
	./main
v: 
	valgrind ./main
d:
	gcc -g -D BUFFER_SIZE=100000 get_next_line.c get_next_line_utils.c
c:
	rm main a.out