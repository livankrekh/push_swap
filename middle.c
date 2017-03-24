/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:24:57 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/20 12:24:59 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		compare(int curr, int next, int middle)
{
	int		diff_curr;
	int		diff_next;

	diff_curr = (curr - middle < 0) ? (curr - middle) * -1 : curr - middle;
	diff_next = (next - middle < 0) ? (next - middle) * -1 : next - middle;
	if (diff_curr > diff_next)
		return (1);
	return (0);
}

int		get_middle_curr(t_stack *a, int max, int min)
{
	int		middle_val;
	int		res;

	middle_val = (max - min) / 2 + min;
	while (a != NULL)
	{
		if (compare(res, a->data, middle_val))
			res = a->data;
		a = a->next;
	}
	return (res);
}

int		get_middle(t_stack *a)
{
	int		middle_val;
	int		res;

	middle_val = (max_a(a) + min_a(a)) / 2;
	while (a != NULL)
	{
		if (compare(res, a->data, middle_val))
			res = a->data;
		a = a->next;
	}
	return (res);
}
