/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:58:18 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 18:02:30 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_free_gnl(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*get_return_value(char *mem_buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!mem_buffer[i])
		return (NULL);
	while (mem_buffer && mem_buffer[i] && mem_buffer[i] != '\n')
		i++;
	str = ft_calloc((i + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (mem_buffer[++i] && mem_buffer && mem_buffer[i] != '\n')
		str[i] = mem_buffer[i];
	if (mem_buffer[i] == '\n')
	{
		str[i] = mem_buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_buffer(char *mem_buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mem_buffer && mem_buffer[i] && mem_buffer[i] != '\n')
		i++;
	if (!mem_buffer[++i])
	{
		free(mem_buffer);
		return (NULL);
	}
	str = malloc((ft_strlen(mem_buffer) - (i - 1)) * sizeof(char));
	if (!str)
		return (ft_free_gnl(mem_buffer));
	i++;
	while (mem_buffer[i])
	{
		str[j++] = mem_buffer[i++];
	}
	str[j] = '\0';
	free(mem_buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*mem_buffer;
	char		*buff_str;
	char		*r_value;
	int			read_val;

	if (fd < 0 || fd > FOPEN_MAX || (read(fd, NULL, 0) == -1))
		return (NULL);
	read_val = 1;
	r_value = NULL;
	while (!(ft_strchr (mem_buffer, '\n')) && read_val > 0)
	{
		buff_str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buff_str)
			return (NULL);
		read_val = read(fd, buff_str, BUFFER_SIZE);
		mem_buffer = ft_strjoin(mem_buffer, buff_str);
		free(buff_str);
	}
	if (!mem_buffer)
		return (NULL);
	r_value = get_return_value(mem_buffer);
	mem_buffer = get_next_buffer(mem_buffer);
	return (r_value);
}
