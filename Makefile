# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 10:16:30 by lbuccher          #+#    #+#              #
#    Updated: 2022/01/10 10:16:32 by lbuccher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRCS = main.c \
		map.c \
		get_next_line.c \
		get_next_line_utils.c \


OBJ = $(SRCS:.c=.o)

INCLUDE = so_long.h \
			#get_next_line.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

.c.o:
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I /usr/local/include $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
