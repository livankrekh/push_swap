/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:37:16 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/19 11:37:18 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		s(t_stack *a, char flag)
{
	int		tmp;
	t_stack	*next;

	if (a != NULL)
	{
		tmp = a->data;
		next = a->next;
		a->data = next->data;
		next->data = tmp;
	}
	if (flag == 'a')
		return (1);
	return (2);
}

int		p(t_stack **target, t_stack **from, char flag)
{
	t_stack	*prev;
	t_stack *tmp;

	if (*from != NULL)
	{
		prev = (t_stack*)malloc(sizeof(t_stack));
		prev->data = (*from)->data;
		prev->next = *target;
		*target = prev;
		tmp = *from;
		*from = (*from)->next;
		free(tmp);
	}
	if (flag == 'a')
		return (11);
	return (12);
}

int		r(t_stack **a, char flag)
{
	t_stack	*curr;
	int		tmp;
	t_stack	*tmp2;

	if (*a == NULL)
		return ((flag == 'a') ? 21 : 22);
	curr = (*a);
	tmp = curr->data;
	while (curr->next != NULL)
	{
		tmp2 = curr->next;
		curr->data = tmp2->data;
		curr = tmp2;
	}
	curr->data = tmp;
	if (flag == 'a')
		return (21);
	return (22);
}

int		reverse(t_stack **a, char flag)
{
	t_stack	*curr;
	int		tmp;
	int		tmp2;

	if (*a == NULL)
		return ((flag == 'a') ? 31 : 32);
	curr = (*a)->next;
	tmp = (*a)->data;
	while (curr != NULL)
	{
		tmp2 = curr->data;
		curr->data = tmp;
		tmp = tmp2;
		curr = curr->next;
	}
	(*a)->data = tmp;
	if (flag == 'a')
		return (31);
	return (32);
}
