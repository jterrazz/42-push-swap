/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:41:24 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 16:41:27 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_fd(t_flags_args *flags)
{
	int fd;

	if (!flags->flag_file)
		return (0);
	fd = open(flags->filename, O_RDONLY);
	return (fd);
}

int		free_ret(char **p)
{
	if (*p)
		free(*p);
	*p = NULL;
	return (0);
}
