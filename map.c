/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:22 by lbuccher          #+#    #+#             */
/*   Updated: 2022/01/14 15:53:28 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int check_ber(char *map)
{
    int len_m;
    int len_f;
    char *format;

    format = malloc(4 + 1);
    format = ".ber\0";
    len_m = ft_strlen(map);
    len_f = ft_strlen(format);
    while (len_f >= 0)
    {
        if (map[len_m] == format[len_f])
        {
            len_m --;
            len_f --;
        }
        else
            return (1);
    }
    return (0);
}
//verifie si la map est bien rectangulaire
int map_rectangle(char *str_map, size_t len)
{
    size_t i;

    i = 0;
    while (str_map[i])
        i++;
    if (i != len)
        return (1);
    return (0);
}

int check_map(char *str_map, t_game *game)
{
    size_t  len;
    int     fd;
    int     matrice_len;
    char    *map_line;

    matrice_len = 0;
    fd = open(str_map, O_RDONLY);
    map_line = get_next_line(fd);
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
    game->size_x = (int)len - 1;
    game->size_y = matrice_len;
    return (matrice_len);
}

char    **init_map(char *map, int matrice_len)
{
    char    **map_mat;
    char    *map_line;
    int     fd;
    int     i;

    i = 0;
    fd = open(map, O_RDONLY);
    map_line = get_next_line(fd);
    map_mat = (char **)malloc((matrice_len + 1) * sizeof(char*));
    if (!map_mat)
        write(1, "fucked up\n", 10); // function that free malloc needed
    while (map_line)
    {
        map_mat[i] = malloc((ft_strlen(map_line) + 1) * sizeof(char));
        if (!map_mat[i])
            write(1, "fucked up\n", 10); // function that free malloc needed
        map_mat[i] = map_line;
        i ++;
        map_line = get_next_line(fd);
    }
    return (map_mat);
}

void create_map(t_game game, char **map)
{
    char *wall = "img/wall.xpm";
    char *perso = "img/perso_2.xpm";
    char *ground = "img/ground.xpm";
    int x;
    int y;

    y = 0;
    while (y < game.size_y)
    {
        x = 0;
        while (x < game.size_x)
        {
            if (map[y][x] == '0')
                add_img(game, ground, x * 24, y * 24);
            else if (map[y][x] == 'P')
            {
                add_img(game, ground, x * 24, y * 24); //ne pas oublier d ajouter un sol avant chaque objet
                add_img(game, perso, x * 24, y * 24);
            }
            else if (map[y][x] == '1')
                add_img(game, wall, x * 24, y * 24);
            x ++;
        }
        y ++;
    }
}
