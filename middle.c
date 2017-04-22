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

int		get_middle_curr(t_stack *a, int size)
{
	int		*arr;
	int		i;
	int		tmp;
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
		{
			tmp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tmp;
			i = 0;
		}
		i++;
	}
	res = arr[size / 2];
	free(arr);
	return (res);
}

