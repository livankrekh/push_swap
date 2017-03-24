/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:35:37 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/20 14:35:38 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_balance(t_stack *a, int min, int middle, char flag)
{
	int		res;

	res = 0;
	while (a != NULL)
	{
		if (flag == 'b')
		{
			if (a->data >= min && a->data <= middle)
				res++;
		}
		else
		{
			if (a->data < middle && a->data > min)
				res++;
		}
		a = a->next;
	}
	return (res);
}

int		presort(t_stack *a, int balance, int middle, int size)
{
	int		res;
	int		index;

	res = 0;
	index = 0;
	while (a != NULL)
	{
		if (a->data < middle)
		{
			if (index >= size / 2)
				res++;
		}
		index++;
		a = a->next;
	}
	if (balance / 2 < res)
		return (1);
	return (0);
}

void	sorting(t_stack **a, t_stack **b, int min, int max)
{
	int		middle;
	int		size;
	int		balance_b;
	int		balance_a;
	int		i;
	int		sign;

	size = count(*a);
	middle = get_middle_curr(*a, min, max);				//Необходимо усовершенствовать алгоритм
	balance_b = count_balance(*a, middle, max, 'b');	//Тут тоже!
	balance_a = count_balance(*a, min, middle, 'a');	//И тут...
	i = 0;
	if (balance_b > 3)
		sorting(a, b, middle, max);
	sign = presort(*a, balance_b, middle, size);
	while (balance_b && i < size)
	{
		if ((*a)->data >= middle && (*a)->data <= max)
		{
			PB;
			balance_b--;
		}
		else
		{
			if (sign == 1)
			{
				RRA;
			}
			else
				RA;
		}
		i++;
	}
	i = 0;
	if (balance_a > 3)
		sorting(a, b, min, middle);
	sign = presort(*a, balance_a, middle, size);
	while (balance_a && a != NULL && i < count(*a) && count(*a) > 3)
	{
		if ((*a)->data < middle && (*a)->data > min)
		{
			PB;
			balance_a--;
		}
		else
		{
			if (sign == 1)
			{
				RA;
			}
			else
				RRA;
		}
		i++;
	}
}
