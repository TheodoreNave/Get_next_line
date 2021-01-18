/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:07:09 by tnave             #+#    #+#             */
/*   Updated: 2021/01/18 16:04:42 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <limits.h>

int		get_next_line(int fd, char **line)
{
	static char buff[MAXOPEN][BUFFER_SIZE];
	char *str;
	int rd;
	int i;

	i = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX || 
			fd == "*.bin" || )
		return (-1);
	if (!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!(buff[fd][0] == 0 || buff[fd] == ""))
	{
		while (ft_strchr(buff[fd], '\n'))
		{
			line[i] += str[i];
			buffer -= str[i];
			i++;
			return (1);
		}
		line[i] += buff;
		buff = NULL;
		i = 0;
		while (rd = read(fd, buff, BUFFER_SIZE) && rd > 0)
		{
			str = ft_strjoin(str, buff);
			if (rd == 0)
			{
				line[i] += buff;
				return (0);
			}
		}
	}
	return (-1);
}

//NEED TO FREE
// Dup La string si elle existe
// join les strings entre elle

int		check_error(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX || fd == "*.bin")
	{
		
	}
}

int main()
{
	
	return (0);
}
