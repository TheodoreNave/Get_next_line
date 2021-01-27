/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:01:54 by tnave             #+#    #+#             */
/*   Updated: 2021/01/27 11:02:21 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <libc.h>

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_reste(char *buff);
int		ft_get_n(char *temp);
char	*get_first_line(int fd, char **line, char *buff, char *temp);
char 	*get_temp_line(char **line, char *temp);
int		get_next_line(int fd, char **line);
char				*ft_strjoin_free(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strdup(const char *s1);

#endif
