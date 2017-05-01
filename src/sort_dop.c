/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 11:58:26 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/23 11:58:27 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_next(t_stack *a, char sign, int len, int middle)
{
	t_stack	*tmp;

	tmp = a;
	while (len-- && tmp != NULL)
	{
		if (sign == 'a' && tmp->data < middle)
			return (1);
		if (sign == 'b' && tmp->data > middle)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_b(t_stack *b, int size)
{
	t_stack	*e2;
	t_stack *e3;

	if (size <= 1)
		return (0);
	e2 = (b->next != NULL) ? b->next : NULL;
	if (e2 != NULL)
		e3 = e2->next;
	if (size == 2)
	{
		if (b->data < e2->data)
			return (1);
	}
	else if (b->data < e2->data && e2->data > e3->data && e3->data < b->data)
		return (1);
	else if (b->data > e2->data && e2->data < e3->data && e3->data > b->data)
		return (2);
	else if (b->data > e2->data && e2->data < e3->data && e3->data < b->data)
		return (3);
	else if (b->data < e2->data && e2->data < e3->data && e3->data > b->data)
		return (4);
	else if (b->data < e2->data && e2->data > e3->data && e3->data > b->data)
		return (5);
	return (0);
}

int		check_a(t_stack *a, int size)
{
	t_stack	*e2;
	t_stack *e3;

	if (size <= 1)
		return (0);
	e2 = (a->next != NULL) ? a->next : NULL;
	if (e2 != NULL)
		e3 = e2->next;
	if (size == 2)
	{
		if (a->data > e2->data)
			return (1);
	}
	else if (a->data > e2->data && e2->data < e3->data && e3->data > a->data)
		return (1);
	else if (a->data < e2->data && e2->data > e3->data && e3->data < a->data)
		return (2);
	else if (a->data < e2->data && e2->data > e3->data && e3->data > a->data)
		return (3);
	else if (a->data > e2->data && e2->data > e3->data && e3->data < a->data)
		return (4);
	else if (a->data > e2->data && e2->data < e3->data && e3->data < a->data)
		return (5);
	return (0);
}

void	simple_sort_b(t_stack **b, int len, t_cmd **cmd)
{
	t_stack	*c;
	t_stack *n;

	if (len == 2)
		return (cmd_list(cmd, SB));
	c = ((*b)->next != NULL) ? (*b)->next : NULL;
	if (c != NULL)
		n = c->next;
	if ((*b)->data < c->data && c->data > n->data && n->data < (*b)->data)
		cmd_list(cmd, SB);
	else if ((*b)->data > c->data && c->data < n->data && n->data > (*b)->data)
		cmd_list(cmd, RRB);
	else if ((*b)->data > c->data && c->data < n->data && n->data < (*b)->data)
	{
		cmd_list(cmd, RRB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data < c->data && c->data < n->data && n->data > (*b)->data)
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data < c->data && c->data > n->data && n->data > (*b)->data)
		cmd_list(cmd, RB);
}

void	simple_sort_a(t_stack **a, int len, t_cmd **cmd)
{
	t_stack	*c;
	t_stack *n;

	c = NULL;
	if (len == 2)
		return (cmd_list(cmd, SA));
	c = ((*a)->next != NULL) ? (*a)->next : NULL;
	if (c != NULL)
		n = c->next;
	if ((*a)->data > c->data && c->data < n->data && n->data > (*a)->data)
		cmd_list(cmd, SA);
	else if ((*a)->data < c->data && c->data > n->data && n->data < (*a)->data)
		cmd_list(cmd, RRA);
	else if ((*a)->data < c->data && c->data > n->data && n->data > (*a)->data)
	{
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data > c->data && c->data > n->data && n->data < (*a)->data)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data > c->data && c->data < n->data && n->data < (*a)->data)
		cmd_list(cmd, RA);
}
