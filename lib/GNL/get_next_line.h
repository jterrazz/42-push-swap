/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:32:22 by jterrazz          #+#    #+#             */
/*   Updated: 2017/05/08 12:13:22 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <stdlib.h>

int	get_next_line(const int fd, char **line);
typedef struct	s_buff
{
	int		buff_size;
	char	buff[BUFF_SIZE];
}				t_buff;

#endif
