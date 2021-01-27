/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:01:38 by tnave             #+#    #+#             */
/*   Updated: 2021/01/27 11:10:22 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strjoin(char *s1, char *s2)
{
	size_t			i;
	size_t			j;
	char			*str;
	size_t			total_size;

	i = 0;
	j = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (total_size) + 1)))
		return (NULL);
	while (s1[j])
		str[i++]= s1[j++];
	j = 0;
	while (s2[j])
	{
		if (s2[j] == '\n')
		{
			str[i] = '\0';
			return (str);	
		}
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char				*ft_strjoin_free(char *s1, char *s2)
{
	size_t			i;
	size_t			j;
	char			*str;
	size_t			total_size;

	i = 0;
	j = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (total_size) + 1)))
		return (NULL);
	while (s1[j])
		str[i++]= s1[j++];
	j = 0;
	while (s2[j])
	{
		if (s2[j] == '\n')
		{
			str[i] = '\0';
			return (str);	
		}
		str[i++] = s2[j++];
	}
	free(s1);
	s1 = NULL;
	str[i] = '\0';
	return (str);
}


char				*ft_reste(char *buff) // on parcours le buff pour checker si y'a un \n et si y'en a un on retourne la str + 1 pour esquiver le \n
{
	int 			i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (&buff[i + 1]);
		i++;
	}
	return (buff);
}

char		*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
