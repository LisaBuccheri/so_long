/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:54:24 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/19 12:18:50 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		s_x;
	int		s_y;
	int		x;
	int		y;
	int		nb_coll;
	int		nb_move;
	char	**map;
	char	*play_p;
	char	*wall_p;
	char	*grou_p;
	char	*coll_p;
	char	*door_p;
	void	*xpm_img;
}	t_game;

typedef struct s_mandatory_char
{
	int	player;
	int	collect;
	int	exit;
}	t_mandatory_char;

int		mouse_move(int mouse);
int		deal_key(int key, t_game *param);
int		ft_close(t_game *game);
int		check_ber(char *map);
int		check_map(char *str_map, t_game *game);
int		check_ess_char(t_game *game, char **map);
int		map_rectangle(char *str_map, size_t len);
char	**init_map(char *map, int matrice_len);
void	init_struct(t_game *game);
void	create_map(t_game *game, char **map);
void	*add_img(t_game *game, char *path, int x_pos, int y_pos);
void	add_img_to_map(t_game *game, char c, int x, int y);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
void	move(t_game *game);
void	exit_game(void);
void	error_exit(char *text);
void	free_matrice(int size, char **map, char *text, int err);

int		count(long int n);
char	*ft_itoa(int n);
void	put_str(t_game *game);

void	add_enemy(t_game *game);
void	is_dead(t_game *game, char c);
void	str_dead(t_game *game);

void	move_enemy(t_game *game);
void	switch_m(t_game *game);

void	enemy_up(t_game *game, int x, int y);
void	enemy_down(t_game *game, int x, int y);
void	enemy_left(t_game *game, int x, int y);
void	enemy_right(t_game *game, int x, int y);

#endif
