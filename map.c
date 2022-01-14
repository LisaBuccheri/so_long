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

int check_map(char *str_map)
{
    size_t  len;
    int     fd;
    int     i;
    char    *map_line;
    //char    **map;    //creer une matrice qui contient les elements de la map

    fd = open(str_map, O_RDONLY);
    i = 0;
    map_line = get_next_line(fd);
    len = ft_strlen(map_line);
    while (map_line)
    {
        if (map_rectangle(map_line, len))
        {
            free(map_line);
            return (1);
        }
        free(map_line);
        map_line = get_next_line(fd);
    }
    return (0);
}
