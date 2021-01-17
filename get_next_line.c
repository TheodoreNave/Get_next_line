/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:07:09 by tnave             #+#    #+#             */
/*   Updated: 2021/01/16 18:03:05 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <limits.h>

int		get_next_line(int fd, char **line)
{
	int i;
	int j;
	char *str;

	ft_strjoin();



	return (0);
}

int		check_buffer_max_error()
{
	if (fd = "*.bin")
		return (-1);
	if (fd = read) // TO MODIFY
		return ();
	if (BUFFER_SIZE > SSIZE_MAX)
		return (-1);
	if (!= EOF)
		return (-1);
	
}

char	full_line(char *s1, )
{

}	

char buf[BUFF + 1];
buf[BUFF] = '\0';

int main()
{

	int fd;
	int rd;

	fd = open("text.txt", O_RDONLY);
	rd = (int)read(fd, buf, BUFF);
	printf("read = %zd\n", rd);
	printf("buf = %s\n", buf);
	printf("read = %zd\n", read(fd, buf, BUFF));
	printf("buf = %s\n", buf);
	printf("read = %zd\n", read(fd, buf, BUFF));
	printf("buf = %s\n", buf);
	printf("read = %zd\n", read(fd, buf, BUFF));
	printf("buf = %s\n", buf);

	return (0);
}
