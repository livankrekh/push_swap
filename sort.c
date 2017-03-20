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

void	print_stack(t_stack *a)
{
	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	printf("-\n");
	printf("a\n");
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

void	sorting(t_stack *a, t_stack *b, int middle)
{
	int		max;

	max = min_a(a);
	while (a->next != NULL)
	{
		while (max != a->data)
			RA;
		PB;
		max = min_a(a);
	}
	PB;
	while (b->next != NULL)
		PA;
	PA;
	print_stack(a);
}
