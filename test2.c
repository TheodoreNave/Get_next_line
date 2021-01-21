/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:41:56 by tnave             #+#    #+#             */
/*   Updated: 2021/01/21 16:21:12 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "get_next_line.h"

size_t		ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);

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

char	*ft_strchr(char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
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

int		ft_is_charset(char c)
{
	int i;

	i = 0;
	if (c == '\n') 
			return (1);
	return (0);
}

int main(void)
{
	int fd;
	static char buffer[BUFFER_SIZE + 1];
	char *str;
	int i;
	int rd;
	char *str2;
	char *temp;
	int len_buf;
	int j;
	char *str3;
	char *strdst;
	
	j = 0;
	i = 0;
	rd = 0;
	fd = open("txt.txt", O_RDONLY);
	buffer[BUFFER_SIZE] = '\0';
	len_buf = ft_strlen(buffer);
	while ((rd = read(fd, buffer, BUFFER_SIZE) > 0))
	{
	//	printf("str = [%s]\n", temp);
	//	printf("buffer = [%s]\n", buffer);
	//	printf("======================================\n");
		while (buffer[i])
		{
			if (!(ft_is_charset(buffer[i])))
			{
				str = ft_strdup(buffer);
				free(str);
			}
			else
			{
				str2 = &buffer[i + 1];
				str3[j] = ft_strjoin(str, str2);
				buffer[i] = '\0';
			}	
			i++;
			j++;
		}
	}
	printf("STR1 = [%s]\n", str);
	printf("STR2 = [%s]\n", str2);
	printf("STR3 = [%s]\n", str3);
//	printf("[%s]", str);
}
