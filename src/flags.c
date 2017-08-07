/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:23:23 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:05:39 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void		init_todo(t_todo *todo, t_list_int **stack_a, t_list_int **stack_b)
{
	todo->ra = 0;
	todo->rra = 0;
	todo->rb = 0;
	todo->rrb = 0;
	todo->stack_a_elements = get_max_index(*stack_a);
	todo->stack_b_elements = 0;
	todo->a_top = 0;
	todo->b_top = 0;
	todo->a_temp = 0;
	todo->b_temp = 0;
	todo->stack_a = stack_a;
	todo->stack_b = stack_b;
}

int			init_flags(t_flags_args *flags, int argc, char **argv)
{
	int i;

	i = 1;
	flags->flag_v = 0;
	flags->flag_file = 0;
	while (i < argc && !str_is_number(argv[i]))
	{
		if (!ft_strcmp(argv[i], "-v"))
			flags->flag_v = 1;
		else if (!ft_strcmp(argv[i], "-f"))
		{
			flags->flag_file = 2;
			i++;
			if (argc == i)
				return (ft_error());
			flags->filename = argv[i];
		}
		else
			return (ft_error());
		i++;
	}
	if (argc == i || argc <= flags->flag_v + flags->flag_file)
		return (ft_error());
	return (1);
}
