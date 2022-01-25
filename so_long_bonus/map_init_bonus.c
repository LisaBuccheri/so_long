/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:23:27 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/18 12:23:29 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	*add_img(t_game *game, char *path, int x_pos, int y_pos)
{
	int		x_y;
	void	*xpm_img;
	void	*mlx;
	void	*win;

	x_y = 24;
	mlx = game->mlx;
	win = game->win;
	xpm_img = mlx_xpm_file_to_image(mlx, path, &x_y, &x_y);
	mlx_put_image_to_window(mlx, win, xpm_img, x_pos * 24, y_pos * 24);
	return (xpm_img);
}

char	**init_map(char *map, int matrice_len)
{
	char	**map_mat;
	char	*map_line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	map_line = get_next_line(fd);
	map_mat = (char **)malloc((matrice_len + 1) * sizeof(char *));
	if (!map_mat)
	{
		free(map_line);
		error_exit("Allocation memory");
	}
	while (map_line)
	{
		map_mat[i] = map_line;
		if (!map_mat[i])
			free_matrice(matrice_len, map_mat, "Allocation memory", 1);
		i ++;
		map_line = get_next_line(fd);
	}
	return (map_mat);
}

void	add_img_to_map(t_game *game, char c, int x, int y)
{
	if (c == '0')
		add_img(game, game->grou_p, x, y);
	else if (c == 'P' && game->x == 0)
	{
		add_img(game, game->grou_p, x, y);
		add_img(game, game->play_p, x, y);
		game->x = x;
		game->y = y;
	}
	else if (c == '1')
		add_img(game, game->wall_p, x, y);
	else if (c == 'E')
		add_img(game, game->door_p, x, y);
	else if (c == 'C')
	{
		game->nb_coll ++;
		add_img(game, game->grou_p, x, y);
		add_img(game, game->coll_p, x, y);
	}
	else
		add_img(game, game->grou_p, x, y);
}

void	create_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	if (check_ess_char(game, map))
		free_matrice(game->s_y, map, "Missing components", 1);
	while (y < game->s_y)
	{
		x = 0;
		while (x < game->s_x)
		{
			if (map[0][x] != '1' || map[game->s_y - 1][x] != '1')
				free_matrice(game->s_y, game->map, "Not  closed by walls", 1);
			if (map[y][0] != '1' || map[y][game->s_x - 1] != '1')
				free_matrice(game->s_y, game->map, "Not  closed by walls", 1);
			add_img_to_map(game, map[y][x], x, y);
			x ++;
		}
		y ++;
	}
	add_enemy(game);
}
