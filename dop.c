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

void	print_stack(t_stack *a, t_stack *b)
{
	int		sign;
	t_stack	*lol;

	sign = 0;
	printf("___________________________________________\n");
	while (a != NULL)
	{
		lol = a->next;
		if (lol != NULL)
		{
			if (a->data > lol->data)
				sign++;
		}
		printf("%d -> ", a->data);
		a = a->next;
	}
	printf("| a\n");
	printf("___________________________________________\n");
	while (b != NULL)
	{
		printf("%d -> ", b->data);
		b = b->next;
	}
	printf("| b\n");
	if (sign != 0)
		printf("\033[31mKO\033[0m\n");
	else
		printf("\033[32mOK\033[0m\n");
	printf("SIGN = %d\n", sign);
}
