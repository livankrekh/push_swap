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

void	back_a(t_stack **a, int rotate, t_cmd **cmd)
{
	int		size;

	size = count(*a);
	if (rotate > size / 2)
	{
		while (size - rotate++ > 0)
			cmd_list(cmd, RA);
	}
	else
	{
		while (rotate--)
			cmd_list(cmd, RRA);
	}
}

void	back_b(t_stack **b, int rotate, t_cmd **cmd)
{
	int		size;

	size = count(*b);
	if (rotate > size / 2 > 0)
	{
		while (size - rotate++)
			cmd_list(cmd, RB);
	}
	else
	{
		while (rotate--)
			cmd_list(cmd, RRB);
	}
}

int		middle_dop(int *arr, int i)
{
	int		tmp;

	tmp = arr[i + 1];
	arr[i + 1] = arr[i];
	arr[i] = tmp;
	return (0);
}

int		get_middle_curr(t_stack *a, int size)
{
	int		*arr;
	int		i;
	int		res;

	i = 0;
	arr = (int*)malloc(sizeof(int) * size);
	while (i < size && a != NULL)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	i = 0;
	while (i + 1 < size)
	{
		if (arr[i] > arr[i + 1])
			i = middle_dop(arr, i);
		else
			i++;
	}
	res = arr[size / 2];
	free(arr);
	return (res);
}
