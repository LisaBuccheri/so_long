/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:39:44 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/18 19:40:00 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_matrice(game->s_y, game->map, NULL, 0);
	return (0);
}

void	exit_game(void)
{
	exit(0);
}

void	error_exit(char *text)
{
	write(1, "Error\n", 6);
	write(1, text, ft_strlen(text));
	exit(0);
}

void	free_matrice(int size, char **map, char *text, int err)
{
	int	i;

	i = size;
	while (--i >= 0)
	{
		if (map[i])
			free(map[i]);
	}
	if (map)
		free(map);
	if (err)
		error_exit(text);
	exit(0);
}
