/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:01:53 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/10 10:01:55 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdio.h>
/*
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
*/
void   ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
			n %= 10;
		}
		ft_putchar(n + '0');
	}
}
//ferme la fenetre lorsque tu cliques sur la croix
int ft_close(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    //pas oublier de free tous les elements qui sauront utiliser dans le jeu
    exit(0);
}
//ferme la fenetre a la detection de la key esc
int deal_key(int key, t_game *param)
{
    if (key == 53)
    {
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        exit(0);
    }
    return(0);
}
//permet d'afficher une image a l'ecran
void add_img(t_game game, char *path, int x_pos, int y_pos)
{
    int x_y = 24;
    //char *path = "img/wall.xpm";
    void *xpm_img = mlx_xpm_file_to_image(game.mlx_ptr, path, &x_y, &x_y);
    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, xpm_img, x_pos, y_pos);
}

int main(int argc, char *argv[])
{
    t_game  game;
    char    **map;
    int     matrice_len;

    if (argc != 2 || check_ber(argv[1]))
    {
        perror(strerror(22));
        return (1);
    }
    matrice_len = check_map(argv[1], &game);
    printf("x: %d\ny: %d", game.size_x, game.size_y);
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, game.size_x * 24, game.size_y * 24, "test");
    if (matrice_len == 1)
    {
        write(1, "Map error", 9);
        return (1);
    }
    map = init_map(argv[1], matrice_len);
    create_map(game, map);
    mlx_key_hook(game.win_ptr, deal_key, &game); //pour les touches
    mlx_hook(game.win_ptr, 17, 0, ft_close, &game);
    mlx_loop(game.mlx_ptr);
    return(0);
}
