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

// int		count_balance(t_stack *a, int min, int middle, char flag)
// {
// 	int		res;

// 	res = 0;
// 	while (a != NULL)
// 	{
// 		if (flag == 'a')
// 		{
// 			if (a->data <= middle && a->data >= min)
// 				res++;
// 		}
// 		else
// 		{
// 			if (a->data < middle && a->data >= min)
// 				res++;
// 		}
// 		a = a->next;
// 	}
// 	return (res);
// }

// int		compare_eff(t_stack *a, int curr, int next)
// {
// 	int 	res_max;
// 	int 	res_min;
// 	int		max;
// 	int		min;
// 	t_stack	*tmp;

// 	res_max = 0;
// 	res_min = 0;
// 	tmp = a;
// 	max = (curr > next) ? curr : next;
// 	min = (curr < next) ? curr : next;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->data > max)
// 			res_max++;
// 		tmp = tmp->next;
// 	}
// 	while (a != NULL)
// 	{
// 		if (a->data < min)
// 			res_min++;
// 		a = a->next;
// 	}
// 	res_max = (res_max >= res_min) ? max : min;
// 	return ((res_max == curr) ? 0 : 1);
// }

// int		compare(t_stack *a, int curr, int next, int middle)
// {
// 	int		diff_curr;
// 	int		diff_next;

// 	diff_curr = (curr - middle < 0) ? (curr - middle) * -1 : curr - middle;
// 	diff_next = (next - middle < 0) ? (next - middle) * -1 : next - middle;
// 	if (diff_curr > diff_next)
// 		return (1);
// 	if (diff_curr == diff_next && curr != next)
// 		return (compare_eff(a, curr, next));
// 	return (0);
// }

// int		get_middle_curr(t_stack *a, int max, int min)
// {
// 	int		middle_val;
// 	int		res;
// 	int		tmp_res;
// 	int		sign;
// 	t_stack	*tmp;

// 	middle_val = (max - min) / 2 + min;
// 	tmp = a;
// 	while (a != NULL)
// 	{
// 		if (compare(tmp, res, a->data, middle_val))
// 			res = a->data;
// 		a = a->next;
// 	}
// 	tmp_res = 0;
// 	while (1)
// 	{
// 		sign = count_balance(a, res, max, 'a') - count_balance(a, min, res, 'b');
// 		if ((count(a) % 2 == 0 && sign == 0) || (count(a) % 2 == 1 && sign == 1))
// 			break ;
// 		a = tmp;
// 		while (a != NULL)
// 		{
// 			if (compare(tmp, tmp_res, a->data, res))
// 				tmp_res = a->data;
// 			a = a->next;
// 		}
// 		res = tmp_res;
// 	}
// 	return (res);
// }

int		get_middle_curr(t_stack *a, int size)
{
	int		*arr;
	int		i;
	int		tmp;

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
	return (arr[size / 2]);
}

