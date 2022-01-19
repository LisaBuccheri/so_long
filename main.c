/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:01:53 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/17 19:52:07 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	deal_key(int key, t_game *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		free_matrice(param->s_y, param->map, NULL, 0);
	}
	else if (key == 13)
		up(param);
	else if (key == 0)
		left(param);
	else if (key == 1)
		down(param);
	else if (key == 2)
		right(param);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	g;
	int		matrice_len;

	if (argc != 2 || check_ber(argv[1]))
		error_exit("Wrong argument");
	g.wall_p = "img/grey_wall.xpm";
	g.play_p = "img/perso_2.xpm";
	g.grou_p = "img/ground.xpm";
	g.coll_p = "img/collect_skull.xpm";
	g.door_p = "img/door_close.xpm";
	g.nb_coll = 0;
	g.x = 0;
	g.nb_move = 0;
	matrice_len = check_map(argv[1], &g);
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
