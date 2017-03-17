/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:01:01 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/17 19:01:02 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_input(t_stack *a, t_stack *b, int *arr, int size)
{
	int 		stack_size;
	int 		i;

	i = 0;
	stack_size = size / 2;
	while (i < stack_size)
	{
		b->data = arr[i];
		b->next = (t_stack*)malloc(sizeof(t_stack));
		b = b->next;
		i++;
	}
	while (size - stack_size)
	{
		a->data = arr[stack_size++];
		a->next = (t_stack*)malloc(sizeof(t_stack));
		a = a->next;
	}
}
