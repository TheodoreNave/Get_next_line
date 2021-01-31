/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:48:46 by tnave             #+#    #+#             */
/*   Updated: 2021/01/29 16:07:01 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char				*ft_strjoin_free(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char				*get_str_new_line(char *new_line)
{
	int				i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	if (ft_strchr(new_line, '\n'))
	{
		while (new_line[i] && new_line[i] != '\n')
			i++;
		str = ft_strdup(new_line + i + 1);
		while (new_line[j])
		{
			new_line[j] = str[j];
			j++;
		}
		new_line[j] = '\0';
		free(str);
		return (new_line);
	}
	return (NULL);
}

int					get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*new_line[256];
	int				len;
	int				rd;

	if (BUFFER_SIZE < 1 || fd < 0 || (read(fd, buff, 0) < 0) || line == NULL)
		return (-1);
	rd = 0;
	if (new_line[fd] == NULL)
		new_line[fd] = ft_strdup("");
	while (!ft_strchr(new_line[fd], '\n') && (rd = read(fd, buff, BUFFER_SIZE)))
	{
		buff[rd] = '\0';
		new_line[fd] = ft_strjoin_free(new_line[fd], buff);
	}
	len = get_len(new_line[fd]);
	*line = ft_substr(new_line[fd], 0, len);
	if (get_str_new_line(new_line[fd]) == NULL)
	{
		free(new_line[fd]);
		new_line[fd] = NULL;
		return (0);
	}
	return (1);
}
