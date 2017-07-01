/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:08:54 by jterrazz          #+#    #+#             */
/*   Updated: 2017/06/14 17:41:23 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ADD STATICS
//CHECK FOLDER NAMES
// Check comments in .h
// HCECK FOLDER NAME AND GNL FILES

static void	init_mvt_tab(t_mvt mvt_tab[11])
{
	mvt_tab[0].str = "sa";
	mvt_tab[0].id = sa;
	mvt_tab[1].str = "sb";
	mvt_tab[1].id = sb;
	mvt_tab[2].str = "ss";
	mvt_tab[2].id = ss;
	mvt_tab[3].str = "pa";
	mvt_tab[3].id = pa;
	mvt_tab[4].str = "pb";
	mvt_tab[4].id = pb;
	mvt_tab[5].str = "ra";
	mvt_tab[5].id = ra;
	mvt_tab[6].str = "rb";
	mvt_tab[6].id = rb;
	mvt_tab[7].str = "rr";
	mvt_tab[7].id = rr;
	mvt_tab[8].str = "rra";
	mvt_tab[8].id = rra;
	mvt_tab[9].str = "rrb";
	mvt_tab[9].id = rrb;
	mvt_tab[10].str = "rrr";
	mvt_tab[10].id = rrr;
}

static int		get_fd(t_flags_args *flags)
{
	int fd;

	if (!flags->flag_file)
		return (0);
	fd = open(flags->filename, O_RDONLY);
	return (fd);
}

int				run_commands(t_list_int **stack_a, t_list_int **stack_b,
	t_mvt mvt_tab[11], t_flags_args *flags)
{
	char		*line;
	int			i;
	int			fd;

	line = NULL;
	show_list(*stack_a, *stack_b, flags->flag_v);
	fd = get_fd(flags);
	if (fd < 0)
		return (ft_error());
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (i <= 11)
		{
			if (i == 11)
			{
				free(line);
				return (ft_error());
			}
			if (!ft_strcmp(mvt_tab[i].str, line))
			{
				disptatch_moves(stack_a, stack_b, mvt_tab[i].id);
				show_list(*stack_a, *stack_b, flags->flag_v);
				break ;
			}
			i++;
		}
		free(line);
	}
	if (line)
		free(line);
	return (are_in_order(*stack_a, *stack_b));
}

int				main(int argc, char **argv)
{
	t_list_int		*stack_a;
	t_list_int		*stack_b;
	t_mvt			mvt_tab[11];
	t_flags_args	flags;

	stack_b = NULL;
	if (argc > 1)
	{
		if (!init_flags(&flags, argc, argv))
			return (0);
		if (!create_stack_base(&stack_a, argc, argv, &flags))
			return (0);
		init_mvt_tab(mvt_tab);
		return (run_commands(&stack_a, &stack_b, mvt_tab, &flags)
			+ list_delete(stack_a) + list_delete(stack_b));
	}
	return (ft_error());
}
