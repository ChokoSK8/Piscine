/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:06:29 by abrun             #+#    #+#             */
/*   Updated: 2020/11/26 13:43:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

char			*get_buf(int fd, int *ret, char *buf);

char			*fill_line(char *buf, char **line);

size_t			get_len_buff(char *buf);

char			*ft_strdup(const char *s);

#endif
