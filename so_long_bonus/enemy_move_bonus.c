/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 03:46:36 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/20 03:46:37 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	switch_m(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->s_y)
	{
		x = -1;
		while (++x < game->s_x)
			if (game->map[y][x] == 'm')
				game->map[y][x] = 'M';
	}
}

void	enemy_up(t_game *game, int x, int y)
{
	if ((y - 1) == game->y && x == game->x)
	{
		move_enemy(game);
		return ;
	}
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'm';
	add_img(game, "img/enemy_1.xpm", x, y - 1);
	add_img(game, game->grou_p, x, y);
}

void	enemy_down(t_game *game, int x, int y)
{
	if ((y + 1) == game->y && x == game->x)
	{
		move_enemy(game);
		return ;
	}
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'm';
	add_img(game, "img/enemy_1.xpm", x, y + 1);
	add_img(game, game->grou_p, x, y);
}

void	enemy_left(t_game *game, int x, int y)
{
	if (y == game->y && (x - 1) == game->x)
	{
		move_enemy(game);
		return ;
	}
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'm';
	add_img(game, "img/enemy_1.xpm", x - 1, y);
	add_img(game, game->grou_p, x, y);
}

void	enemy_right(t_game *game, int x, int y)
{
	if (y == game->y && (x + 1) == game->x)
	{
		move_enemy(game);
		return ;
	}
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'm';
	add_img(game, "img/enemy_1.xpm", x + 1, y);
	add_img(game, game->grou_p, x, y);
}
