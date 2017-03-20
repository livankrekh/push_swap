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
# define SA s(a, "sa");
# define SB s(b, "sb");
# define SS ss(a, b);
# define PA p(&a, &b, "pa");
# define PB p(&b, &a, "pb");
# define RA r(&a, "ra");
# define RB r(&b, "rb");
# define RR rr(&a, &b);
# define RRA reverse(&a, "rra", 0);
# define RRB reverse(&b, "rrb", 0);
# define RRR reverse(&a, &b);
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

typedef	struct 	s_stack
{
	int 		data;
	void		*next;
}				t_stack;

int 			stack_input(t_stack *a, char **argv, int argc);
void			s(t_stack *a, char *flag);
void			ss(t_stack *a, t_stack *b);
void			p(t_stack **target, t_stack **from, char *flag);
void			r(t_stack **a, char *flag);
void			reverse(t_stack **a, char *flag, int i);
int				get_middle(t_stack *a);
void			sorting(t_stack *a, t_stack *b, int middle);
int				max_a(t_stack *a);
int				min_a(t_stack *a);
void			print_stack(t_stack *a);

#endif
