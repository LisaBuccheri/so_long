/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:42:00 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/19 16:42:17 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	put_str(t_game *game)
{
	int		x;
	char	*nb_move;

	x = -1;
	nb_move = ft_itoa(game->nb_move);
	while (++x < 5)
		add_img(game, game->wall_p, x, 0);
	mlx_string_put(game->mlx, game->win, 5, 1, 15, nb_move);
	free(nb_move);
}

int	count(long int n)
{
	int	nb;

	nb = 0;
	if (n <= 0)
	{
		n *= -1;
		nb++;
	}
	while (n > 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	n2;
	int			i;
	int			stop;

	n2 = (long int) n;
	i = count(n2);
	str = malloc((i + 1) * sizeof(char));
	stop = 0;
	if (!str)
		return (NULL);
	while (i > stop)
	{
		str[i - 1] = n2 % 10 + '0';
		n2 /= 10;
		i--;
	}
	str[count(n)] = '\0';
	return (str);
}
