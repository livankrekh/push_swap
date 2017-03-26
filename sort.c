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
		if (flag == 'a')
		{
			if (a->data <= middle && a->data >= min)
				res++;
		}
		else
		{
			if (a->data < middle && a->data >= min)
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
		if (a->data > middle)
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

void	sort(t_stack **a, int size)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if ((*a)->next != NULL)
		elem2 = (*a)->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if (size < 3)
	{
		if ((*a)->data > elem2->data)
			SA;
	}
	else if ((*a)->data > elem2->data && elem2->data < elem3->data && elem3->data > (*a)->data)
	{
		SA;
	}
	else if ((*a)->data < elem2->data && elem2->data > elem3->data && elem3->data < (*a)->data)
	{
		RA;
		SA;
		RRA;
		SA;
	}
	else if ((*a)->data < elem2->data && elem2->data > elem3->data && elem3->data > (*a)->data)
	{
		RA;
		SA;
		RRA;
	}
	else if ((*a)->data > elem2->data && elem2->data > elem3->data && elem3->data < (*a)->data)
	{
		SA;
		RA;
		SA;
		RRA;
		SA;
	}
	else if ((*a)->data > elem2->data < elem3->data && elem3->data < (*a)->data)
	{
		SA;
		RA;
		SA;
		RRA;
	}
}

// void	reverse_sort(t_stack **b, int size)
// {
// 	t_stack	*elem2;
// 	t_stack *elem3;

// 	elem2 = NULL;
// 	elem3 = NULL;
// 	if ((*a)->next != NULL)
// 		elem2 = (*a)->next;
// 	if (elem2 != NULL)
// 		elem3 = elem2->next;
// 	if (size < 3)
// 	{
// 		if ((*a)->data > elem2->data)
// 			SA;
// 	}
// 	if ((*a)->data )
// }

void	reverse_sorting(t_stack **a, t_stack **b, int size, int min)
{
	int		balance_a;
	int		middle;
	int		balance_b;
	int		count;
	int		i;

	count = 0;
	i = 0;
	middle = get_middle_curr(*b, min, max_a(*b));
	balance_a = count_balance(*b, middle, max_a(*b), 'a');
	balance_b = count_balance(*b, min, middle, 'b');
	if (balance_a > 3)
		reverse_sorting(a, b, balance_a, middle);
	while (balance_a && i < size + 1)
	{
		if ((*b)->data >= middle)
		{
			PA;
			balance_a--;
		}
		else
		{
			RB;
			count++;
		}
		i++;
	}
	while (count--)
		RRB;
	sort(a, size);
	printf("MIDDLE = %d\n", middle);
	print_stack(*a, *b);
	if (balance_b > 3)
		reverse_sorting(a, b, balance_b, min);
	count = 0;
	i = 0;
	while (balance_b && i < size + 1)
	{
		if ((*b)->data < middle && (*b)->data >= min)
		{
			PA;
			balance_b--;
		}
		else
		{
			RB;
			count++;
		}
		i++;
	}
	while (count--)
		RRB;
	sort(a, size);
	printf("MIDDLE = %d\n", middle);
	print_stack(*a, *b);
	// if (is_sorted(*a) == 1)
	// 	printf("\033[32mOK!!!\033[0m");
	// else
	// 	printf("\033[31mKO!!!\033[0m");
}

void	sorting(t_stack **a, t_stack **b, int min, int max)
{
	int		middle;
	int		size;
	int		balance_b;
	int		balance_a;
	int		i;
	int		sign;
	int		balance_copy;

	size = count(*a);
	middle = get_middle_curr(*a, min, max);
	balance_b = count_balance(*a, min, middle, 'b');
	balance_copy = balance_b;
	balance_a = count_balance(*a, middle, max, 'a');
	i = 0;
	sign = presort(*a, balance_b, middle, size);
	while (balance_b)
	{
		if ((*a)->data < middle && (*a)->data >= min)
		{
			PB;
			balance_b--;
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
	if (balance_a > 3)
		sorting(a, b, middle, max);
	if (count(*a) < 4)
		sort(a, count(*a));
	//printf("BALANCE_B = %d\n", balance_copy);
	printf("ENTER\n");
	reverse_sorting(a, b, balance_copy, min);
}


	// while (balance_a && i < size)
	// {
	// 	if ((*a)->data >= middle && (*a)->data <= max)
	// 	{
	// 		PB;
	// 		balance_a--;
	// 	}
	// 	else
	// 	{
	// 		if (sign == 1)
	// 		{
	// 			RA;
	// 		}
	// 		else
	// 			RRA;
	// 	}
	// 	i++;
	// }

// void	sorting(t_stack **a, t_stack **b, int min, int max)
// {
// 	int		middle;
// 	int		i;
// 	int		balance_b;
// 	int		sign;
// 	int		size;
// 	t_stack	*tmp;

// 	tmp = *a;
// 	size = count(*a);
// 	middle = get_middle_curr(*a, min, max);
// 	balance_b = count_balance(*a, min, middle, 'b');
// 	while (size > 3 && get_middle_curr(*a, min, max))
// 	{
// 		middle = get_middle_curr(*a, min, max);
// 		balance_b = count_balance(*a, min, middle, 'b');
// 		printf("BALANCE = %d\n", balance_b);
// 		printf("MIDDLE = %d\n", middle);
// 		sign = presort(*a, balance_b, middle, count(*a));
// 		i = 0;
// 		while (balance_b && i < size)
// 		{
// 			if ((*a)->data < middle && (*a)->data >= min)
// 			{
// 				// printf("i = %d\n", balance_b);
// 				PB;
// 				balance_b--;
// 			}
// 			// else
// 			// {
// 			// 	if (sign == 1)
// 			// 	{
// 			// 		RA;
// 			// 	}
// 			// 	else
// 			// 		RRA;
// 			// }
// 			RA;
// 			i++;
// 		}
// 		size = count(*a);
// 		min = middle;
// 	}
// }
