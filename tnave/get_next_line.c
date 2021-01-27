/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:09:31 by tnave             #+#    #+#             */
/*   Updated: 2021/01/27 11:20:01 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_get_n(char *temp) // on parcours la temp jusqu'a trouver un \n
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char				*get_temp_line(char **line, char *temp)
{
	char *str;

	str = ft_strdup("");
	str = ft_strjoin_free(str, temp);
	free(*line);
	*line = str;
	temp = ft_reste(temp);
	return (temp);
}

char				*get_first_line(int fd, char **line, char *buff, char *temp)
{
	int				i;
	char			*str;
	int				rd;
	
	i = 0;
	str = ft_strdup("");
	rd = 0;
	if (temp != NULL)
		str = ft_strjoin_free(str, temp);
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)	// On read le txt
	{
		str = ft_strjoin_free(str, buff);
		while (buff[i] && i < rd)			// Tant qu'on a pas fini de lire on avance avec un index dans buff
		{
			if (buff[i] =='\n')				// si on tombe sur un \n
			{
				*line = str;				// stock la str qui a ete join dans line
				buff[rd] = '\0';
				temp = ft_reste(buff);		// ft_temp permet de 
				return (temp);				
			}
			i++;
		}	
		i = 0;				// On parcours a nouveau a chaque fois
	}
	return (NULL);
}

int					get_next_line(int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1];
	static char		*temp;

	if (BUFFER_SIZE < 1 || line == NULL || fd < 0)
		return (-1);
	if (temp == NULL)
	{
		temp = get_first_line(fd, line, buff, temp);
		if (temp != NULL)
			return (0);
		return (1);
	}
	if (temp != NULL && ft_get_n(temp) == 0)
	{
		temp = get_first_line(fd, line, buff, temp);
		return (1);
	}
	if (temp != NULL && ft_get_n(temp) == 1)
	{
		temp = get_temp_line(line, temp);
		return (1);
	}
	return (-1);
}
