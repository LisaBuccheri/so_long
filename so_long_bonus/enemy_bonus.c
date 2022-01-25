/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:22:27 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/19 17:22:29 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	add_enemy(t_game *game)
{
	int	i;
	int	nb_enemy;
	int	pos_x;
	int	pos_y;

	i = 0;
	nb_enemy = (rand() % ((game->s_y * game->s_x) / 20) + 1);
	while (nb_enemy)
	{
		pos_x = (rand() % (game->s_x - 2)) + 1;
		pos_y = (rand() % (game->s_y - 2)) + 1;
		if (game->map[pos_y][pos_x] == '0')
		{
			add_img(game, "img/enemy_1.xpm", pos_x, pos_y);
			game->map[pos_y][pos_x] = 'M';
			nb_enemy --;
		}
	}
	return ;
}

void	move_enemy(t_game *game)
{
	int	x;
	int	y;
	int	m;

	y = -1;
	while (++y < game->s_y)
	{
		x = -1;
		while (++x < game->s_x)
		{
			m = rand() % 4;
			if (game->map[y][x] == 'M')
			{
				if (m == 0 && game->map[y][x + 1] == '0')
					enemy_right(game, x, y);
				else if (m == 1 && game->map[y][x - 1] == '0')
					enemy_left(game, x, y);
				else if (m == 2 && game->map[y + 1][x] == '0')
					enemy_down(game, x, y);
				else if (m == 3 && game->map[y - 1][x] == '0')
					enemy_up(game, x, y);
			}
		}
	}
	switch_m(game);
}

void	is_dead(t_game *game, char c)
{
	if (c == 'M' || c == 'm')
	{
		printf("GAME OVER!\n");
		free_matrice(game->s_y, game->map, NULL, 0);
	}
}
