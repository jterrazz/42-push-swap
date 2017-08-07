/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 15:01:51 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:05:37 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_index_min(t_list_int *stack_a)
{
	int min;
	int index;
	int i;

	i = 0;
	index = 0;
	while (stack_a)
	{
		if (!i)
			min = stack_a->value;
		else if (min > stack_a->value)
		{
			min = stack_a->value;
			index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (index);
}

int			get_index_min_second(int index_min, t_list_int *stack_a)
{
	int min;
	int index;
	int i;

	i = 0;
	index = 0;
	while (stack_a)
	{
		if (i == index_min)
		{
			stack_a = stack_a->next;
			continue ;
		}
		if (!i)
			min = stack_a->value;
		else if (min > stack_a->value)
		{
			min = stack_a->value;
			index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (index);
}

int			get_max_index(t_list_int *stack_a)
{
	int i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int			get_index_of_max(t_list_int *stack_a)
{
	int i;
	int max_value;
	int	i_max;

	i = 0;
	i_max = 0;
	max_value = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		i++;
		if (stack_a->value > max_value)
		{
			max_value = stack_a->value;
			i_max = i;
		}
		stack_a = stack_a->next;
	}
	return (i_max);
}

int			get_value_of_last(t_list_int *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}
