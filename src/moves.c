/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:23:23 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 16:41:11 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_switch_top(t_list_int **list, char *print, t_todo *todo)
{
	t_list_int *first;
	t_list_int *second;

	if (todo)
		make_todo(todo->stack_a, todo->stack_b, todo);
	first = *list;
	*list = (*list)->next;
	second = *list;
	first->next = (*list)->next;
	second->next = first;
	*list = second;
	if (print)
		ft_putstr(print);
}

void	list_rotate(t_list_int **list, char *print, t_todo *todo)
{
	t_list_int *first;
	t_list_int *temp;

	if (todo && print)
	{
		if (!ft_strcmp(print, "ra\n") && todo->rra > 0)
			todo->rra--;
		else if (!ft_strcmp(print, "rb\n") && todo->rrb > 0)
			todo->rrb--;
		else if (!ft_strcmp(print, "ra\n"))
			todo->ra++;
		else if (!ft_strcmp(print, "rb\n"))
			todo->rb++;
	}
	else
	{
		first = *list;
		*list = (*list)->next;
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		first->next = NULL;
		temp += (print ? ft_putstr_ret(print) : 0);
	}
}

void	list_reverse_rotate(t_list_int **list, char *print, t_todo *todo)
{
	t_list_int *last;
	t_list_int *first;

	if (todo && print)
	{
		if (!ft_strcmp(print, "rra\n") && todo->ra > 0)
			todo->ra--;
		else if (!ft_strcmp(print, "rrb\n") && todo->rb > 0)
			todo->rb--;
		else if (!ft_strcmp(print, "rra\n"))
			todo->rra++;
		else if (!ft_strcmp(print, "rrb\n"))
			todo->rrb++;
	}
	else
	{
		last = *list;
		while (last->next->next)
			last = last->next;
		first = last->next;
		last->next = NULL;
		first->next = *list;
		*list = first;
		last += (print ? ft_putstr_ret(print) : 0);
	}
}

void	list_push(t_list_int **dest, t_list_int **src,
	char *print, t_todo *todo)
{
	t_list_int *current;

	if (!(*src))
		return ;
	if (todo)
		make_todo(todo->stack_a, todo->stack_b, todo);
	current = *src;
	*src = (*src)->next;
	if (!(*dest))
	{
		*dest = current;
		current->next = NULL;
	}
	else
	{
		current->next = *dest;
		*dest = current;
	}
	if (print)
		ft_putstr(print);
}
