/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:54:24 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/11 15:54:27 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    int  size_x;
    int  size_y;
}   t_game;

typedef struct s_img
{
    int x;
    int y;
    char *path;
    void *xpm_img;
}   t_img;

void    ft_putchar(char c);
void	ft_putnbr(int n);
int     mouse_move(int mouse);
int     deal_key(int key, t_game *param);
int     ft_close(t_game *game);
int     check_ber(char *map);
int     check_map(char *str_map, t_game *game);
int     map_rectangle(char *str_map, size_t len);
char    **init_map(char *map, int matrice_len);
void    create_map(t_game game, char **map);
void    add_img(t_game game, char *path, int x_pos, int y_pos);
