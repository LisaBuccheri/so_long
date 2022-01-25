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

NAME_B = bonus

DIR_B = so_long_bonus/

SRCS = $(wildcard *.c)

SRCS_B = $(DIR_B)main_bonus.c \
		$(DIR_B)map_check_bonus.c \
		$(DIR_B)end_bonus.c \
		$(DIR_B)get_next_line_bonus.c \
		$(DIR_B)get_next_line_utils_bonus.c \
		$(DIR_B)move_bonus.c \
		$(DIR_B)enemy_bonus.c \
		$(DIR_B)enemy_move_bonus.c \
		$(DIR_B)map_init_bonus.c \
		$(DIR_B)move_print_bonus.c \

OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:.c=.o)

INCLUDE = so_long.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

.c.o:
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I /usr/local/include $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B): $(OBJ_B)
	$(CC) $(FLAGS) -I /usr/local/include $(OBJ_B) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all $(NAME_B)
