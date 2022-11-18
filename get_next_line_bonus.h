/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:10:44 by msekhsou          #+#    #+#             */
/*   Updated: 2022/11/18 09:11:50 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<limits.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int i);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif