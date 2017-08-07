/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_dispatcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:29:32 by jterrazz          #+#    #+#             */
/*   Updated: 2017/08/07 15:05:34 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		list_moves(t_list_int **stack, enum e_mvt mvt)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	if (mvt == sa || mvt == sb || mvt == ss)
		list_switch_top(stack, 0, NULL);
	else if (mvt == ra || mvt == rb || mvt == rr)
		list_rotate(stack, 0, NULL);
	else if (mvt == rra || mvt == rrb || mvt == rrr)
		list_reverse_rotate(stack, 0, NULL);
}

void			disptatch_moves(t_list_int **stack_a, t_list_int **stack_b,
	enum e_mvt mvt)
{
	if (mvt == sa || mvt == ra || mvt == rra || mvt == ss ||
		mvt == rr || mvt == rrr)
		list_moves(stack_a, mvt);
	if (mvt == sb || mvt == rb || mvt == rrb || mvt == ss ||
		mvt == rr || mvt == rrr)
		list_moves(stack_b, mvt);
	if (mvt == pa)
		list_push(stack_a, stack_b, 0, NULL);
	else if (mvt == pb)
		list_push(stack_b, stack_a, 0, NULL);
}
