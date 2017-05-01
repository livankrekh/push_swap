/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:55:21 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/21 15:55:22 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_list_a(t_stack **a)
{
	t_stack	*next;
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*a = NULL;
}

int		min_a(t_stack *a)
{
	int		res;

	res = a->data;
	while (a != NULL)
	{
		if (res > a->data)
			res = a->data;
		a = a->next;
	}
	return (res);
}

int		max_a(t_stack *a)
{
	int		res;

	res = a->data;
	while (a != NULL)
	{
		if (res < a->data)
			res = a->data;
		a = a->next;
	}
	return (res);
}

int		count(t_stack *a)
{
	int		i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int		is_sorted(t_stack *a)
{
	t_stack	*tmp;

	if (a == NULL)
		return (0);
	while (a->next != NULL)
	{
		tmp = a->next;
		if (a->data > tmp->data)
			return (0);
		a = a->next;
	}
	return (1);
}
