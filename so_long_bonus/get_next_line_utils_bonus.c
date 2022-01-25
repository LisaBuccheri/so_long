/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:39:15 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 18:13:06 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (unsigned char) c)
		s++;
	if (*s == (unsigned char) c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*join;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	join = ft_calloc((len + 1), sizeof(char));
	if (!join)
		return (ft_free_gnl(s1));
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, nmemb * size);
	return (str);
}
