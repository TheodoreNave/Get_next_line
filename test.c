/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:13:24 by tnave             #+#    #+#             */
/*   Updated: 2021/01/20 14:34:16 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *s1);

int		main(void)
{
	int i;
	int fd;
	int rd;
	static char buffer[BUFFER_SIZE + 1];
	char *str = "";
	char *str2 = "";
	char *temp;

	i = 0;
	rd = 0;
	fd = open("txt.txt", O_RDONLY);

	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		while (buffer[i] && i < rd)
		{
			printf("[%c]\n", buffer[i]);
			i++;
			str = ft_strjoin(str, buffer);
			if (buffer[i] == '\n')
				temp = ft_strdup(&buffer[i + 1]);
		}
		printf("=========================\n");
		i = 0;
	}
	printf("[%s]\n", str);
	printf("[%s]", temp);
	return (0);
}
