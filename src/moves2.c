/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:03:47 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:03:53 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		make_todo_next(t_list_int **stack_a, t_list_int **stack_b,
	t_todo *todo)
{
	while (todo->rra > 0 && todo->rrb > 0)
	{
		list_reverse_rotate(stack_a, "rrr\n", NULL);
		list_reverse_rotate(stack_b, NULL, NULL);
		todo->rra--;
		todo->rrb--;
	}
	while (todo->rra > 0)
	{
		list_reverse_rotate(stack_a, "rra\n", NULL);
		todo->rra--;
	}
	while (todo->rrb > 0)
	{
		list_reverse_rotate(stack_b, "rrb\n", NULL);
		todo->rrb--;
	}
}

void			make_todo(t_list_int **stack_a,
	t_list_int **stack_b, t_todo *todo)
{
	while (todo->ra > 0 && todo->rb > 0)
	{
		list_rotate(stack_a, "rr\n", NULL);
		list_rotate(stack_b, NULL, NULL);
		todo->ra--;
		todo->rb--;
	}
	while (todo->ra > 0)
	{
		list_rotate(stack_a, "ra\n", NULL);
		todo->ra--;
	}
	while (todo->rb > 0)
	{
		list_rotate(stack_b, "rb\n", NULL);
		todo->rb--;
	}
	make_todo_next(stack_a, stack_b, todo);
}
