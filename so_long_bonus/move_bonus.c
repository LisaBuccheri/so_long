/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:17:20 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/18 15:17:22 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	move(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	if (game->map[game->y][game->x] == 'C')
	{
		game->nb_coll --;
		game->map[game->y][game->x] = '0';
	}
	while (++y < game->s_y && game->nb_coll == 0)
	{
		x = -1;
		while (++x < game->s_x)
		{
			if (game->map[y][x] == 'E')
			{
				add_img(game, "img/door_open.xpm", x, y);
				game->map[y][x] = 'e';
			}
		}
	}
	game->nb_move ++;
	put_str(game);
	if (game->map[game->y][game->x] == 'e')
		free_matrice(game->s_y, game->map, NULL, 0);
}

void	up(t_game *game)
{
	char	c_wall;

	c_wall = game->map[game->y -1][game->x];
	if (c_wall != '1' && game->map[game->y -1][game->x] != 'E')
	{
		add_img(game, game->grou_p, game->x, game->y);
		game->y -= 1;
		is_dead(game, c_wall);
		move_enemy(game);
		add_img(game, game->play_p, game->x, game->y);
		move(game);
		printf("%d\n", game->nb_move);
	}
}

void	down(t_game *game)
{
	char	c_wall;

	c_wall = game->map[game->y +1][game->x];
	if (c_wall != '1' && game->map[game->y +1][game->x] != 'E')
	{
		add_img(game, game->grou_p, game->x, game->y);
		game->y += 1;
		is_dead(game, c_wall);
		move_enemy(game);
		add_img(game, game->play_p, game->x, game->y);
		move(game);
		printf("%d\n", game->nb_move);
	}
}

void	left(t_game *game)
{
	char	c_wall;

	c_wall = game->map[game->y][game->x -1];
	if (c_wall != '1' && game->map[game->y][game->x -1] != 'E')
	{
		add_img(game, game->grou_p, game->x, game->y);
		game->x -= 1;
		is_dead(game, c_wall);
		move_enemy(game);
		add_img(game, game->play_p, game->x, game->y);
		move(game);
		printf("%d\n", game->nb_move);
	}
}

void	right(t_game *game)
{
	char	c_wall;

	c_wall = game->map[game->y][game->x +1];
	if (c_wall != '1' && game->map[game->y][game->x +1] != 'E')
	{
		add_img(game, game->grou_p, game->x, game->y);
		game->x += 1;
		is_dead(game, c_wall);
		move_enemy(game);
		add_img(game, game->play_p, game->x, game->y);
		move(game);
		printf("%d\n", game->nb_move);
	}
}
