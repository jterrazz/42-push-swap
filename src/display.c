/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:05:46 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:05:41 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static void		show_line_one(t_list_int *stack, int right)
{
	if (right)
	{
		ft_printf("|                      |");
		ft_printf("| %-20d |\n", stack->value);
	}
	else
		ft_printf("| %-20d ||                      |\n", stack->value);
}

static void		show_line_both(t_list_int *stack_a, t_list_int *stack_b)
{
	ft_printf("| %-20d |", stack_a->value);
	ft_printf("| %-20d |\n", stack_b->value);
}

void			show_list(t_list_int *stack_a, t_list_int *stack_b, int print)
{
	if (print)
	{
		ft_printf("|======= LIST A ================ LIST B =======|\n");
		while (stack_a || stack_b)
		{
			if (stack_a && stack_b)
			{
				show_line_both(stack_a, stack_b);
				stack_a = stack_a->next;
				stack_b = stack_b->next;
			}
			else if (stack_a)
			{
				show_line_one(stack_a, 0);
				stack_a = stack_a->next;
			}
			else if (stack_b)
			{
				show_line_one(stack_b, 20);
				stack_b = stack_b->next;
			}
		}
		ft_printf("|==============================================|\n\n");
	}
}
