/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:31:38 by tnave             #+#    #+#             */
/*   Updated: 2021/01/18 14:56:46 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

/*
 * (Voir Schema) 
 *	ft_strjoin pour relier ligne entre elle et les mallocs
 *	substr -> ?
 *	strdup -> Dupliquer ligne pour pouvoir les lire une par une
 *
 *
 *
 *
 *
 *
 *
 *
*/


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

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t				i;
	size_t				j;
	char				*str;
	size_t				total_size;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (total_size) + 1)))
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	char			*str;
	unsigned int	max;

	str = (char*)s;
	i = 0;
	if (!s)
		return (NULL);
	max = ft_strlen(s);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && len && start < max)
	{
		dest[i] = s[start];
		i++;
		start++;
		len--;
	}
	dest[i] = '\0';
	return ((char*)dest);
}
// Secure le substr

char	*ft_strcpy(char const *dst, char const *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	src[i] = '\0';
	return (dst);
}

