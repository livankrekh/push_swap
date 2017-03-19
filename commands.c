/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:37:16 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/19 11:37:18 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *a, char *flag)
{
	int		tmp;
	t_stack	*next;

	tmp = a->data;
	next = a->next;
	a->data = next->data;
	next->data = tmp;
	ft_putstr(flag);
	ft_putstr("\n");
}

void	ss(t_stack *a, t_stack *b)
{
	s(a, "");
	s(b, "ss");
}

void	p(t_stack **target, t_stack **from, char *flag)
{
	t_stack	*prev;
	t_stack *tmp;

	if (*from == NULL)
		return ;
	prev = (t_stack*)malloc(sizeof(t_stack));
	prev->data = (*from)->data;
	prev->next = *target;
	*target = prev;
	tmp = *from;
	*from = (*from)->next;
	free(tmp);
	ft_putstr(flag);
	ft_putstr("\n");
}

void	r(t_stack **a, char *flag)
{
	t_stack	*curr;
	int		tmp;
	int		tmp2;

	curr = (*a)->next;
	tmp = (*a)->data;
	while (curr->next != NULL)
	{
		tmp2 = curr->data;
		curr->data = tmp;
		tmp = tmp2;
		curr = curr->next;
	}
	(*a)->data = tmp;
	ft_putstr(flag);
	ft_putstr("\n");
}

void	rr(t_stack **a, t_stack **b)
{
	r(a, "");
	r(b, "rr");
}

void	reverse(t_stack **a, char *flag, int i)
{
	int		*arr;
	t_stack	*ptr;

	ptr = *a;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	arr = (int*)malloc(sizeof(int) * i);
	ptr = *a;
	while (ptr->next != NULL)
	{
		arr[--i] = ptr->data;
		ptr = ptr->next;
	}
	ptr = *a;
	while (ptr->next != NULL)
	{
		ptr->data = arr[i++];
		ptr = ptr->next;
	}
	free(arr);
	ft_putstr(flag);
	ft_putstr("\n");
}
