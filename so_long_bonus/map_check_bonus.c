/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:22 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/14 15:53:28 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	check_ber(char *map)
{
	int		len_m;

	len_m = ft_strlen(map);
	if (map[len_m - 1] != 'r')
		return (1);
	if (map[len_m - 2] != 'e')
		return (1);
	if (map[len_m - 3] != 'b')
		return (1);
	if (map[len_m - 4] != '.')
		return (1);
	return (0);
}

int	map_rectangle(char *str_map, size_t len)
{
	size_t	i;

	i = 0;
	while (str_map[i])
		i++;
	if (i != len)
		return (1);
	return (0);
}

int	check_map(char *str_map, t_game *game)
{
	size_t	len;
	int		fd;
	int		matrice_len;
	char	*map_line;

	matrice_len = 0;
	fd = open(str_map, O_RDONLY);
	map_line = get_next_line(fd);
	if (!map_line)
		return (0);
	len = ft_strlen(map_line);
	while (map_line)
	{
		if (map_rectangle(map_line, len))
		{
			free(map_line);
			return (1);
		}
		matrice_len ++;
		free(map_line);
		map_line = get_next_line(fd);
	}
	game->s_x = (int)len - 1;
	game->s_y = matrice_len;
	return (matrice_len);
}

int	check_ess_char(t_game *game, char **map)
{
	int					x;
	int					y;
	t_mandatory_char	ess_char;

	y = -1;
	ess_char.player = 0;
	ess_char.collect = 0;
	ess_char.exit = 0;
	while (++y < game->s_y)
	{
		x = -1;
		while (++x < game->s_x)
		{
			if (map[y][x] == 'P')
				ess_char.player = 1;
			else if (map[y][x] == 'C')
				ess_char.collect = 1;
			else if (map[y][x] == 'E')
				ess_char.exit = 1;
		}
	}
	if (ess_char.player == 1 && ess_char.collect == 1 && ess_char.exit == 1)
		return (0);
	return (1);
}
