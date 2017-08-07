/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:39:42 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:04:43 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		arg_is_valid(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '+' && *str != '-'
			&& !(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int		are_in_order(t_list_int *stack_a, t_list_int *stack_b)
{
	int last_value;

	if (stack_b)
		return (ft_putstr_ret("KO\n"));
	last_value = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->value <= last_value)
			return (ft_putstr_ret("KO\n"));
		last_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (ft_putstr_ret("OK\n"));
}

int		is_in_order(t_list_int *stack_a)
{
	int last_value;

	last_value = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->value <= last_value)
			return (0);
		last_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}
