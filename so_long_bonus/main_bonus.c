/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:01:53 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/17 19:52:07 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	deal_key(int key, t_game *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		free_matrice(param->s_y, param->map, NULL, 0);
	}
	else if (key == 13 || key == 126)
		up(param);
	else if (key == 0 || key == 123)
		left(param);
	else if (key == 1 || key == 125)
		down(param);
	else if (key == 2 || key == 124)
		right(param);
	return (0);
}

void	init_struct(t_game *game)
{
	game->wall_p = "img/grey_wall.xpm";
	game->play_p = "img/perso_2.xpm";
	game->grou_p = "img/ground.xpm";
	game->coll_p = "img/collect_skull.xpm";
	game->door_p = "img/door_close.xpm";
	game->nb_coll = 0;
	game->x = 0;
	game->nb_move = 0;
}

int	main(int argc, char *argv[])
{
	t_game	g;
	int		matrice_len;

	if (argc != 2 || check_ber(argv[1]))
		error_exit("Wrong argument");
	init_struct(&g);
	matrice_len = check_map(argv[1], &g);
	if (matrice_len == 0)
		error_exit("Empty file directory");
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.s_x * 24, g.s_y * 24, "so_long");
	if (matrice_len == 1)
		error_exit("Wrong map size");
	g.map = init_map(argv[1], matrice_len);
	create_map(&g, g.map);
	mlx_string_put(g.mlx, g.win, 5, 1, 15, "0");
	mlx_key_hook(g.win, deal_key, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g);
	mlx_loop(g.mlx);
	return (0);
}
