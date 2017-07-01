/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:16:53 by jterrazz          #+#    #+#             */
/*   Updated: 2017/06/22 11:10:47 by jterrazz         ###   ########.fr       */
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

int		get_index_of_max(t_list_int *stack_a)
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

int		get_value_of_last(t_list_int *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

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

int			create_stack_base(t_list_int **stack_a, int argc, char **argv, t_flags_args *flags)
{
	int i;
	int is_int;
	t_list_int *current_a;

	i = 1;
	if (flags)
		i += flags->flag_v + flags->flag_file;
	while (i < argc)
	{
		if (!arg_is_valid(argv[i]))
			return (list_delete(*stack_a) + ft_error());
		while (*argv[i])
		{
			if ((*argv[i] >= '0' && *argv[i] <= '9') || *argv[i] == '-' || *argv[i] == '+')
			{
				if (!(*stack_a))
				{
					*stack_a = list_new(ft_atoi(&argv[i], &is_int));
					current_a = *stack_a;
				}
				else
				{
					current_a->next = list_new(ft_atoi(&argv[i], &is_int));
					current_a = current_a->next;
				}
				if (!is_int)
					return (list_delete(*stack_a) + ft_error());
			} // peut etre si different despace error
			else
				(argv[i])++;
		}
		i++;
	}
	return (stack_is_valid(*stack_a));
}
