/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:34:59 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 16:51:43 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		try_switch_firsts(t_list_int *stack_a, int min_index,
	t_list_int **stack_a_move, t_todo *todo)
{
	int		first;
	int		second;

	if (min_index > 1)
		return (0);
	first = stack_a->value;
	stack_a = stack_a->next;
	if (!stack_a)
		return (0);
	second = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->value < second || stack_a->value < first)
			return (0);
		stack_a = stack_a->next;
	}
	list_switch_top(stack_a_move, "sa\n", todo);
	return (1);
}

static int		try_switch_extremes(t_list_int *stack_a,
	t_list_int **stack_a_move, t_todo *todo)
{
	int			first;
	int			last;
	t_list_int	*sav;

	sav = stack_a;
	first = stack_a->value;
	stack_a = stack_a->next;
	while (sav->next)
		sav = sav->next;
	last = sav->value;
	while (stack_a)
	{
		if (stack_a->value > last || stack_a->value < first)
			return (0);
		stack_a = stack_a->next;
	}
	list_reverse_rotate(stack_a_move, "rra\n", todo);
	list_switch_top(stack_a_move, "sa\n", todo);
	return (1);
}

static int		try_switch_three(t_list_int *stack_a,
	t_list_int **stack_a_move, t_todo *todo)
{
	int first;
	int second;
	int third;

	if (get_max_index(stack_a) == 3)
	{
		first = stack_a->value;
		stack_a = stack_a->next;
		second = stack_a->value;
		stack_a = stack_a->next;
		third = stack_a->value;
		if (first < second && second > third && third > first)
		{
			list_reverse_rotate(stack_a_move, "rra\n", todo);
			list_switch_top(stack_a_move, "sa\n", todo);
			return (1);
		}
		if (first > second && second > third && first > third)
		{
			list_switch_top(stack_a_move, "sa\n", todo);
			list_reverse_rotate(stack_a_move, "rra\n", todo);
			return (1);
		}
	}
	return (0);
}

void			place_in_top(t_list_int **stack, int index, t_todo *todo,
	char c)
{
	int r_needed;
	int rr_needed;
	int max_index;

	max_index = (c == 'a' ? todo->stack_a_elements : todo->stack_b_elements);
	index = index % max_index;
	r_needed = index;
	rr_needed = max_index - index;
	if (r_needed < rr_needed)
	{
		while (r_needed--)
			list_rotate(stack, c == 'a' ? "ra\n" : "rb\n", todo);
	}
	else
	{
		while (rr_needed--)
			list_reverse_rotate(stack, c == 'a' ? "rra\n" : "rrb\n", todo);
	}
}

void			resolver_simple(t_list_int **stack_a,
	t_list_int **stack_b, t_todo *todo)
{
	int i_min;

	if (!is_in_order(*stack_a) && try_switch_three(*stack_a, stack_a, todo))
		return ;
	else
	{
		while (*stack_a && !is_in_order(*stack_a))
		{
			i_min = get_index_min(*stack_a);
			if (try_switch_extremes(*stack_a, stack_a, todo)
				|| (i_min && try_switch_firsts(*stack_a, i_min, stack_a, todo)))
				i_min = 0;
			else if (!is_in_order(*stack_a))
				place_in_top(stack_a, i_min, todo, 'a');
			make_todo(stack_a, stack_b, todo);
			if (is_in_order(*stack_a))
				break ;
			list_push(stack_b, stack_a, "pb\n", todo);
			todo->stack_a_elements--;
			todo->stack_b_elements++;
		}
	}
}
