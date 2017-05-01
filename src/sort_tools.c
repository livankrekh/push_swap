/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:44:53 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/22 19:44:54 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_dop(t_stack **b, t_cmd **cmd, t_stack *c, t_stack *n)
{
	if ((*b)->data < c->data && c->data > n->data && n->data < (*b)->data)
		cmd_list(cmd, SB);
	else if ((*b)->data < c->data && c->data > n->data && n->data > (*b)->data)
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data > c->data && c->data < n->data && n->data < (*b)->data)
	{
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data < c->data && c->data < n->data && n->data > (*b)->data)
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
		cmd_list(cmd, SB);
	}
}

void	sort_b(t_stack **b, int size, t_cmd **cmd)
{
	t_stack	*c;
	t_stack *n;

	c = NULL;
	if (size == 1)
		return ;
	if ((*b)->next != NULL)
		c = (*b)->next;
	if (c != NULL)
		n = c->next;
	if (size == 2)
	{
		if ((*b)->data < c->data)
			cmd_list(cmd, SB);
	}
	else if ((*b)->data > c->data && c->data < n->data && n->data > (*b)->data)
	{
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
		cmd_list(cmd, SB);
	}
	else
		sort_b_dop(b, cmd, c, n);
}

void	sort_dop(t_stack **a, t_cmd **cmd, t_stack *c, t_stack *n)
{
	if ((*a)->data > c->data && c->data < n->data && n->data > (*a)->data)
		cmd_list(cmd, SA);
	else if ((*a)->data < c->data && c->data > n->data && n->data > (*a)->data)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
	}
	else if ((*a)->data > c->data && c->data > n->data && n->data < (*a)->data)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data > c->data && c->data < n->data && n->data < (*a)->data)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
	}
}

void	sort(t_stack **a, int size, t_cmd **cmd)
{
	t_stack	*c;
	t_stack *n;

	c = NULL;
	if (size == 1)
		return ;
	if ((*a)->next != NULL)
		c = (*a)->next;
	if (c != NULL)
		n = c->next;
	if (size == 2)
	{
		if ((*a)->data > c->data)
			cmd_list(cmd, SA);
	}
	else if ((*a)->data < c->data && c->data > n->data && n->data < (*a)->data)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else
		sort_dop(a, cmd, c, n);
}
