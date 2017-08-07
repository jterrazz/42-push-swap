/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:16:53 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:03:23 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_int	*list_new(int value)
{
	t_list_int	*el;

	if ((el = (t_list_int *)malloc(sizeof(t_list_int))) == NULL)
		return (NULL);
	el->value = value;
	el->next = NULL;
	return (el);
}

int			list_delete(t_list_int *list)
{
	t_list_int	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	return (0);
}

int			stack_is_valid(t_list_int *stack)
{
	t_list_int	*stack_sav;
	int			nb;

	while (stack)
	{
		stack_sav = stack;
		nb = stack->value;
		stack = stack->next;
		while (stack)
		{
			if (stack->value == nb)
				return (list_delete(stack) + ft_error());
			stack = stack->next;
		}
		stack_sav = stack_sav->next;
		stack = stack_sav;
	}
	return (1);
}

static int	add_to_stack(t_list_int **stack_a, char **argv,
	t_list_int **current_a, int i)
{
	int is_int;

	is_int = 1;
	if (!(*stack_a))
	{
		*stack_a = list_new(ft_atoi_int(&argv[i], &is_int));
		*current_a = *stack_a;
	}
	else
	{
		(*current_a)->next = list_new(ft_atoi_int(&argv[i], &is_int));
		*current_a = (*current_a)->next;
	}
	if (!is_int)
		return (list_delete(*stack_a) + ft_error());
	return (1);
}

int			create_stack_base(t_list_int **stack_a, int argc, char **argv,
	t_flags_args *flags)
{
	int			i;
	t_list_int	*current_a;

	i = 1;
	if (flags)
		i += flags->flag_v + flags->flag_file;
	while (i < argc)
	{
		if (!arg_is_valid(argv[i]))
			return (list_delete(*stack_a) + ft_error());
		while (*argv[i])
		{
			if ((*argv[i] >= '0' && *argv[i] <= '9') || *argv[i] == '-'
				|| *argv[i] == '+')
			{
				if (!add_to_stack(stack_a, argv, &current_a, i))
					return (0);
			}
			else
				(argv[i])++;
		}
		i++;
	}
	return (stack_is_valid(*stack_a));
}
