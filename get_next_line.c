/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:07:09 by tnave             #+#    #+#             */
/*   Updated: 2021/01/19 11:05:04 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <limits.h>
#define MAX_OPEN 23
#define BUFFER_SIZE 32

int		get_next_line(int fd, char **line)
{
	static char buff[MAX_OPEN][BUFFER_SIZE];
	char *str;
	int rd;
	int i;

	i = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX)
		return (-1);
	if (!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!(buff[fd][0] == 0))
	{
		while (ft_strchr(buff[fd],'\n'))
		{
			line += str[i];
			**buff -= str[i];
			i++;
			return (1);
		}
		line += **buff;
		i = 0;
		while ((rd = read(fd, buff, BUFFER_SIZE) && rd > 0))
		{
			if (rd == 0)
			{
				line += **buff;
				return (0);
			}
		}
	}
	return (-1);
}

//NEED TO FREE
// Dup La string si elle existe
// join les strings entre elle
// Si .bin dans fd -> -1
/*
int		check_error(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX || fd == "*.bin")
	{
		
	}
}
*/
int main(void)
{
	
	return (0);
}

