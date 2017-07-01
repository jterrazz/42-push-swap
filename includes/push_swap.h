/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:14:39 by jterrazz          #+#    #+#             */
/*   Updated: 2017/06/22 15:42:02 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO CLEANER MAKEFILE
//static
// norminette generale

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct	s_list_int
{
	int					value;
	struct s_list_int	*next;
}				t_list_int;

enum	e_mvt {
	none,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct	s_mvt
{
	char		*str;
	enum e_mvt	id;
}				t_mvt;

typedef struct	s_flags_args
{
	int			flag_v;
	int			flag_file;
	char		*filename;
}				t_flags_args;

typedef struct	s_todo
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			stack_a_elements;
	int			stack_b_elements;
	int			a_top;
	int			b_top;
	int			a_temp;
	int			b_temp;
	struct s_list_int **stack_a;
	struct s_list_int **stack_b;
}				t_todo;

int			list_delete(t_list_int *list);
t_list_int	*list_new(int value);
int			arg_is_valid(char *str);
int			ft_error(void);
void		show_list(t_list_int *stack, t_list_int *stack2, int print);
void		list_rotate(t_list_int **list, char *print, t_todo *todo);
void		list_reverse_rotate(t_list_int **list, char *print, t_todo *todo);
void		list_push(t_list_int **dest, t_list_int **src, char *print, t_todo *todo);
void		list_switch_top(t_list_int **list, char *print, t_todo *todo);
int			init_flags(t_flags_args *flags, int argc, char **argv);
int			are_in_order(t_list_int *stack_a, t_list_int *stack_b);
int			is_in_order(t_list_int *stack_a);
int			get_max_index(t_list_int *stack_a);
int			get_index_min(t_list_int *stack_a);
int			get_index_min_second(int index_min, t_list_int *stack_a);
int			get_index_of_max(t_list_int *stack_a);
void		resolver_simple(t_list_int **stack_a, t_list_int **stack_b, t_todo *todo);
void		init_todo(t_todo *todo, t_list_int **stack_a, t_list_int **stack_b);
void		make_todo(t_list_int **stack_a, t_list_int **stack_b, t_todo *todo);

void		place_in_top(t_list_int **stack_a, int index, t_todo *todo, char c);

void		resolver_optimized(t_list_int **stack_a, t_list_int **stack_b,
	t_todo *todo);

void		disptatch_moves(t_list_int **stack_a, t_list_int **stack_b,
	enum e_mvt mvt);

int			create_stack_base(t_list_int **stack_a, int argc,
	char **argv, t_flags_args *flags);

int		get_value_of_last(t_list_int *stack);

#endif
