/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver_optimized.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 17:52:10 by jterrazz          #+#    #+#             */
/*   Updated: 2017/06/22 15:55:28 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // DEL

int			get_rotation_needed_for_i(int i, int max)
{
	int r_needed;
	int rr_needed;

	i = i % max;
	r_needed = i;
	rr_needed = max - i;
	if (r_needed < rr_needed)
		return (r_needed);
	else
		return (rr_needed);
}

// send 2 elements at start
int			get_b_rotation_needed(t_list_int *stack_b, int value_to_place, t_todo *todo)
{
	int i; // find index with closest value to VTP but under
	int best_value;
	int best_i;

	i = 0;
	best_value = stack_b->value;
	best_i = 0;
	stack_b = stack_b->next;
	while (stack_b)
	{
		i++;
		if ((best_value > value_to_place && stack_b->value < best_value) ||
			(best_value < value_to_place && stack_b->value > best_value && stack_b->value < value_to_place))
		{
			best_value = stack_b->value;
			best_i = i;
		}
		stack_b = stack_b->next;
	}
	if (best_value > value_to_place)
		best_i = best_i + 1;
	best_i = best_i % todo->stack_b_elements;
	todo->b_temp = best_i;
	return (get_rotation_needed_for_i(best_i, todo->stack_b_elements));
}

int			get_best_a_index(t_list_int *stack_a, t_list_int *stack_b, t_todo *todo)
{
	int		best_i;
	int		best_weight;
	int		current_weight;
	int		i;

	i = 0;
	best_i = 0;
	best_weight = get_rotation_needed_for_i(i, todo->stack_a_elements) + get_b_rotation_needed(stack_b, stack_a->value, todo) + 1;
	stack_a = stack_a->next;
	i++;
	todo->b_top = todo->b_temp;
	while (stack_a)
	{
		current_weight = get_rotation_needed_for_i(i, todo->stack_a_elements) + get_b_rotation_needed(stack_b, stack_a->value, todo) + 1;
		if (current_weight < best_weight)
		{
			best_i = i;
			best_weight = current_weight;
			todo->b_top = todo->b_temp;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (best_i);
}

int			is_stack_min(t_list_int *stack_a, t_list_int *stack_b)
{
	int min_a;
	int max_b;

	if (!stack_b || !stack_a)
		return (1);
	min_a = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->value < min_a)
			min_a = stack_a->value;
		stack_a = stack_a->next;
	}
	max_b = stack_b->value;
	stack_b = stack_b->next;
	while (stack_b)
	{
		if (stack_b->value > max_b)
			max_b = stack_b->value;
		stack_b = stack_b->next;
	}
	if (min_a > max_b)
		return (1);
	return (0);
}

void		resolver_optimized(t_list_int **stack_a, t_list_int **stack_b, t_todo *todo) // check errirs if b dont exist
{
	int first;
	int second;

	first = (*stack_a)->value;
	list_push(stack_b, stack_a, "pb\n", todo);
	second = (*stack_a)->value;
	list_push(stack_b, stack_a, "pb\n", todo);
	todo->stack_b_elements += 2;
	todo->stack_a_elements -= 2;
	if (first < second)
		list_rotate(stack_b, "rb\n", todo);
	while (*stack_a && (!is_stack_min(*stack_a, *stack_b) || !is_in_order(*stack_a))) // tant que a est dans l'ordre est est min
	{
		todo->a_top = get_best_a_index(*stack_a, *stack_b, todo);
		place_in_top(stack_a, todo->a_top, todo, 'a');
		place_in_top(stack_b, todo->b_top, todo, 'b');
		list_push(stack_b, stack_a, "pb\n", todo);
		todo->stack_a_elements--;
		todo->stack_b_elements++;
	}
	place_in_top(stack_b, get_index_of_max(*stack_b), todo, 'b');
}
// add opti in searcher
// check git files (rm te);
