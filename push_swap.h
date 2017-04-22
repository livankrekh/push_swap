/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:45:01 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/17 17:45:03 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT 0 - 2147483648
# define SA s(*a, 'a')
# define SB s(*b, 'b')
# define SS ss(*a, *b)
# define PA p(a, b, 'a')
# define PB p(b, a, 'b')
# define RA r(a, 'a')
# define RB r(b, 'b')
# define RR rr(a, b)
# define RRA reverse(a, 'a')
# define RRB reverse(b, 'b')
# define RRR rrr(a, b)
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef	struct 	s_cmd
{
	char		*data;
	void		*next;
}				t_cmd;

typedef	struct 	s_inf
{
	int 		len;
	int 		pushed;
}				t_inf;

typedef	struct 	s_stack
{
	int 		data;
	void		*next;
}				t_stack;

int 			stack_input(t_stack **a, char **argv, int argc);
int 			s(t_stack *a, char flag);
int 			ss(t_stack *a, t_stack *b);
int 			p(t_stack **target, t_stack **from, char flag);
int 			r(t_stack **a, char flag);
int 			rr(t_stack **a, t_stack **b);
int 			rrr(t_stack **a, t_stack **b);
int 			reverse(t_stack **a, char flag);
int				max_a(t_stack *a);
int				min_a(t_stack *a);
void			print_stack(t_stack *a, t_stack *b);
int				is_sorted(t_stack *a);
void			sort_b(t_stack **b, int size, t_cmd **cmd);
void			sort(t_stack **a, int size, t_cmd **cmd);
int				count_balance(t_stack *a, int min, int middle, char flag);
int				count(t_stack *a);
void			sorting_a(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd);
int				get_middle_curr(t_stack *a, int size);
int 			return_print();

#endif
