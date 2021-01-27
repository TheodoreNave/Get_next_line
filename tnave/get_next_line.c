/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:09:31 by tnave             #+#    #+#             */
/*   Updated: 2021/01/27 16:22:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_get_n(char *temp) // on parcours la temp jusqu'a trouver un \n
{
	size_t i;

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
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (rd == 0)
			return (NULL);
		str = ft_strjoin_free(str, buff);
		while (buff[i] && i < rd)
		{
			if (buff[i] =='\n')
			{
				*line = str;
				buff[rd] = '\0';
				temp = ft_reste(buff);
				return (temp);				
			}
			i++;
		}	
		i = 0;
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
		if (!(temp = get_first_line(fd, line, buff, temp)))
			return (0);
		return (1);
	}
	if (temp != NULL && !ft_get_n(temp))
	{
		if (!(temp = get_first_line(fd, line, buff, temp)))
			return (0);
		return (1);
	}
	if (temp != NULL && ft_get_n(temp))
	{
		temp = get_temp_line(line, temp);
		return (1);
	}
	return (-1);
}
/*
int		main()
{
	int		fd;
	char	**line;
	char	*str;
	int		i;

	i = 0;
	line = &str;
	fd = open("txt.txt", O_RDONLY);
	printf("************** GNL 1 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 2 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 3 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 4 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 5 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 6 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 7 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 8 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);
	printf("************** GNL 9 ***************\n");
	printf("Return : %d\n", get_next_line(fd, line));
	printf("Line   : ------------------------------>%s\n", *line);



	while (get_next_line(fd, line) != 0)
		printf("%s\n", *line);
	return (0);
}*/
