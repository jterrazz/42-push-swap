/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 21:32:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/05/08 16:16:55 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// si static buff alors read du buff sinon read
// free tout

int		join_line(char *str, char **line)
{
	char *line_sav;

	if (*line)
	{
		line_sav = *line;
		*line = ft_strjoin(*line, str);
		free(line_sav);
		free(str);
	}
	else
		*line = str;
	//check retur valuei
	if (*line == NULL)
		return (-1);
	return (1);
}

int		cpy_buffer(t_buff *buff, char **line)
{
	int i;
	char *str;
	int ret;

	i = 0;
	ret = 0;
	str = ft_strnew(buff->buff_size);
	if (!str)
		return (-1);
	while (i < buff->buff_size)
	{
		if (!buff->buff[i] || buff->buff[i] == '\n')
		{
			ft_memmove(buff->buff, buff->buff + i + 1, BUFF_SIZE - i);
			if (buff->buff_size)
				buff->buff_size = buff->buff_size - i - 1;
			else
				buff->buff_size = i;
			ret = 1;
			break ;
		}
		str[i] = buff->buff[i];
		i++;
	}
	if (join_line(str, line) == -1) // check err
		return (-1);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	static t_buff	buff;
	int		found;

	ret = 1;
	found = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (buff.buff_size > 0 && cpy_buffer((&buff), line))
		return (1);
	while (!found)
	{
		ret = read(fd, buff.buff, BUFF_SIZE);
		buff.buff_size = ret;
		if (ret < 0)
			return (-1);
		else if (!ret)
		{
			if (*line)
				return (1);
			else
				return (0);
		}
		found = cpy_buffer((&buff), line);
		if (found == -1)
			return (-1);
	}
	return (1);
}

/* 
// DELETE AT END !!!
int 	main(int argc, char **argv)
{
	char *line;
	int fd;
	int	ret;
	int i = 4;
	ret = 111;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while (ret > 0 && i--)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
		printf("line -> %s\n", line);
		printf("ret  -> %d\n", ret);
printf("\n\n");
	}
	return (0);
}

*/
