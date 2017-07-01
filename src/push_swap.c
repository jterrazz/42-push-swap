/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:45:11 by jterrazz          #+#    #+#             */
/*   Updated: 2017/06/22 09:56:05 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check makefile deleting dont exist
// check arg 2 0 - 12

static void			sort_stack(t_list_int **stack_a, t_list_int **stack_b)
{
	t_todo	todo;

	init_todo(&todo, stack_a, stack_b);
	if (todo.stack_a_elements > 7)
		resolver_optimized(stack_a, stack_b, &todo);
	else
		resolver_simple(stack_a, stack_b, &todo);
	make_todo(stack_a, stack_b, &todo);
	while (*stack_b)
		list_push(stack_a, stack_b, "pa\n", &todo);
}

int					main(int argc, char **argv)
{
	t_list_int		*stack_a;
	t_list_int		*stack_b;
	t_flags_args	flags;

	if (argc > 1)
	{
		if (!init_flags(&flags, argc, argv))
			return (0);
		if (!create_stack_base(&stack_a, argc, argv, &flags))
			return (0);
		sort_stack(&stack_a, &stack_b);
		list_delete(stack_a);
		list_delete(stack_b);
	}
	return (0);
}
