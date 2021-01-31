/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:48:55 by tnave             #+#    #+#             */
/*   Updated: 2021/01/29 16:07:04 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
int		get_len(char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*get_str_new_line(char *new_line);
int		get_next_line(int fd, char **line);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
