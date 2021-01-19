/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:13:24 by tnave             #+#    #+#             */
/*   Updated: 2021/01/19 12:03:01 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int		main(void)
{
	int i;
	int fd;
	int rd;
	static char buffer[BUFFER_SIZE];

	i = 0;
	rd = 0;
	fd = open("txt.txt", O_RDONLY);

	while ((rd = read(fd, buffer, BUFFER_SIZE)) && rd >= 0)
	{
		//printf("[%c]", buffer[i]);
		while (buffer[i] && i < rd)
		{
		//	printf("[%c]", buffer[i]);
			if (buffer[i] != '\n')
			{
				printf("buff = [%c]\n", buffer[i]);
			}
			i++;
		}
		i = 0;
	}
	return (0);
}
