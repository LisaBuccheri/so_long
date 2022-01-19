/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:22:27 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/19 17:22:29 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	add_enemy(t_game *game)
{
	int	i;
	int	nb_enemy;
	int	pos_x;
	int	pos_y;

	i = 0;
	nb_enemy = (rand() % ((game->s_y * game->s_x) / 10) + 1);
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

void	is_dead(t_game *game, char c)
{
	if (c == 'M')
	{
		printf("GAME OVER!\n");
		free_matrice(game->s_y, game->map, NULL, 0);
	}
}
