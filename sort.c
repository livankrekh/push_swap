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

void	cmd_list(t_cmd **cmd, int sign)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	tmp2 = (*cmd);
	tmp = (t_cmd*)malloc(sizeof(t_cmd));
	tmp->data = ft_strnew((sign > 30) ? 4 : 3);
	tmp->next = NULL;
	if (sign == 1)
		ft_strncpy(tmp->data, "sa\n", 3);
	else if (sign == 2)
		ft_strncpy(tmp->data, "sb\n", 3);
	else if (sign == 3)
		ft_strncpy(tmp->data, "ss\n", 3);
	else if (sign == 11)
		ft_strncpy(tmp->data, "pa\n", 3);
	else if (sign == 12)
		ft_strncpy(tmp->data, "pb\n", 3);
	else if (sign == 21)
		ft_strncpy(tmp->data, "ra\n", 3);
	else if (sign == 22)
		ft_strncpy(tmp->data, "rb\n", 3);
	else if (sign == 23)
		ft_strncpy(tmp->data, "rr\n", 3);
	else if (sign == 31)
		ft_strncpy(tmp->data, "rra\n", 4);
	else if (sign == 32)
		ft_strncpy(tmp->data, "rrb\n", 4);
	else if (sign == 33)
		ft_strncpy(tmp->data, "rrr\n", 4);
	if (*cmd == NULL)
		*cmd = tmp;
	else
	{
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}

int		check_b(t_stack *b, int size)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if (size <= 1)
		return (0);
	if (b->next != NULL)
		elem2 = b->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if (size == 2)
	{
		if (b->data < elem2->data)
			return (1);
	}
	else if (b->data < elem2->data && elem2->data > elem3->data && elem3->data < b->data)
		return (1);
	else if (b->data > elem2->data && elem2->data < elem3->data && elem3->data > b->data)
		return (2);
	else if (b->data > elem2->data && elem2->data < elem3->data && elem3->data < b->data)
		return (3);
	else if (b->data < elem2->data && elem2->data < elem3->data && elem3->data > b->data)
		return (4);
	else if (b->data < elem2->data && elem2->data > elem3->data && elem3->data > b->data)
		return (5);
	return (0);
}

int		check_a(t_stack *a, int size)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if (size <= 1)
		return (0);
	if (a->next != NULL)
		elem2 = a->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if (size == 2)
	{
		if (a->data > elem2->data)
			return (1);
	}
	else if (a->data > elem2->data && elem2->data < elem3->data && elem3->data > a->data)
		return (1);
	else if (a->data < elem2->data && elem2->data > elem3->data && elem3->data < a->data)
		return (2);
	else if (a->data < elem2->data && elem2->data > elem3->data && elem3->data > a->data)
		return (3);
	else if (a->data > elem2->data && elem2->data > elem3->data && elem3->data < a->data)
		return (4);
	else if (a->data > elem2->data && elem2->data < elem3->data && elem3->data < a->data)
		return (5);
	return (0);
}

void	simple_sort_b(t_stack **b, int len, t_cmd **cmd)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if (len == 2)
	{
		cmd_list(cmd, SB);
		return ;
	}
	if ((*b)->next != NULL)
		elem2 = (*b)->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if ((*b)->data < elem2->data && elem2->data > elem3->data && elem3->data < (*b)->data)
		cmd_list(cmd, SB);
	else if ((*b)->data > elem2->data && elem2->data < elem3->data && elem3->data > (*b)->data)
		cmd_list(cmd, RRB);
	else if ((*b)->data > elem2->data && elem2->data < elem3->data && elem3->data < (*b)->data)
	{
		cmd_list(cmd, RRB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data < elem2->data && elem2->data < elem3->data && elem3->data > (*b)->data)
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data < elem2->data && elem2->data > elem3->data && elem3->data > (*b)->data)
		cmd_list(cmd, RB);
}

void	simple_sort_a(t_stack **a, int len, t_cmd **cmd)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if (len == 2)
	{
		cmd_list(cmd, SA);
		return ;
	}
	if ((*a)->next != NULL)
		elem2 = (*a)->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if ((*a)->data > elem2->data && elem2->data < elem3->data && elem3->data > (*a)->data)
		cmd_list(cmd, SA);
	else if ((*a)->data < elem2->data && elem2->data > elem3->data && elem3->data < (*a)->data)
		cmd_list(cmd, RRA);
	else if ((*a)->data < elem2->data && elem2->data > elem3->data && elem3->data > (*a)->data)
	{
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data > elem2->data && elem2->data > elem3->data && elem3->data < (*a)->data)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data > elem2->data && elem2->data < elem3->data && elem3->data < (*a)->data)
		cmd_list(cmd, RA);
}

void	sort_all(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	int		a_check;
	int		b_check;

	a_check = check_a(*a, param.len);
	b_check = check_b(*b, param.pushed);
	if (a_check == b_check)
	{
		if (a_check == 1)
			cmd_list(cmd, SS);
		else if (a_check == 2)
		{
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SS);
		}
		else if (a_check == 3)
		{
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
		}
		else if (a_check == 4)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SS);
		}
		else if (a_check == 5)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
		}
	}
	else
	{
		if (a_check == 1 && b_check == 2)
		{
			cmd_list(cmd, RB);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRB);
			cmd_list(cmd, SB);
		}
		else if (a_check == 1 && b_check == 3)
		{
			cmd_list(cmd, RB);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRB);
		}
		else if (a_check == 1 && b_check == 4)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RB);
			cmd_list(cmd, SB);
			cmd_list(cmd, RRB);
			cmd_list(cmd, SB);
		}
		else if (a_check == 1 && b_check == 5)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RB);
			cmd_list(cmd, SB);
			cmd_list(cmd, RRB);
		}
		else if (a_check == 2 && b_check == 1)
		{
			cmd_list(cmd, RA);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRA);
			cmd_list(cmd, SA);
		}
		else if (a_check == 2 && b_check == 3)
		{
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SA);
		}
		else if (a_check == 2 && b_check == 4)
		{
			cmd_list(cmd, RA);
			cmd_list(cmd, SS);
			cmd_list(cmd, RB);
			cmd_list(cmd, SB);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SS);
		}
		else if (a_check == 2 && b_check == 5)
		{
			cmd_list(cmd, RA);
			cmd_list(cmd, SS);
			cmd_list(cmd, RB);
			cmd_list(cmd, RRA);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRB);
		}
		else if (a_check == 3 && b_check == 1)
		{
			cmd_list(cmd, RA);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRA);
		}
		else if (a_check == 3 && b_check == 2)
		{
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SB);
		}
		else if (a_check == 3 && b_check == 4)
		{
			cmd_list(cmd, SB);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SB);
		}
		else if (a_check == 3 && b_check == 5)
		{
			cmd_list(cmd, SB);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
		}
		else if (a_check == 4 && b_check == 1)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RA);
			cmd_list(cmd, SA);
			cmd_list(cmd, RRA);
			cmd_list(cmd, SA);
		}
		else if (a_check == 4 && b_check == 2)
		{
			cmd_list(cmd, SA);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SS);
		}
		else if (a_check == 4 && b_check == 3)
		{
			cmd_list(cmd, SA);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SA);
		}
		else if (a_check == 4 && b_check == 5)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SA);
		}
		else if (a_check == 5 && b_check == 1)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RA);
			cmd_list(cmd, SA);
			cmd_list(cmd, RRA);
		}
		else if (a_check == 5 && b_check == 2)
		{
			cmd_list(cmd, SA);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SB);
		}
		else if (a_check == 5 && b_check == 3)
		{
			cmd_list(cmd, SA);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
		}
		else if (a_check == 5 && b_check == 4)
		{
			cmd_list(cmd, SS);
			cmd_list(cmd, RR);
			cmd_list(cmd, SS);
			cmd_list(cmd, RRR);
			cmd_list(cmd, SB);
		}
		else if (a_check == 0)
		{
			if (count(*b) <= 3)
				simple_sort_b(b, param.pushed, cmd);
			else
				sort_b(b, param.pushed, cmd);
		}
		else if (b_check == 0)
		{
			if (count(*a) <= 3)
				simple_sort_a(a, param.len, cmd);
			else
				sort(a, param.len, cmd);
		}
	}
}

void	sort_b(t_stack **b, int size, t_cmd **cmd)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if (size == 1)
		return ;
	if ((*b)->next != NULL)
		elem2 = (*b)->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if (size == 2)
	{
		if ((*b)->data < elem2->data)
			cmd_list(cmd, SB);
	}
	else if ((*b)->data > elem2->data && elem2->data < elem3->data && elem3->data > (*b)->data) //2
	{
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
		cmd_list(cmd, SB);
	}
	else if ((*b)->data < elem2->data && elem2->data > elem3->data && elem3->data < (*b)->data) //1
		cmd_list(cmd, SB);
	else if ((*b)->data < elem2->data && elem2->data > elem3->data && elem3->data > (*b)->data) //5
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data > elem2->data && elem2->data < elem3->data && elem3->data < (*b)->data) //3
	{
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if ((*b)->data < elem2->data && elem2->data < elem3->data && elem3->data > (*b)->data) //4
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
		cmd_list(cmd, SB);
	}
}

void	sort(t_stack **a, int size, t_cmd **cmd)
{
	t_stack	*elem2;
	t_stack *elem3;

	elem2 = NULL;
	elem3 = NULL;
	if (size == 1)
		return ;
	if ((*a)->next != NULL)
		elem2 = (*a)->next;
	if (elem2 != NULL)
		elem3 = elem2->next;
	if (size == 2)
	{
		if ((*a)->data > elem2->data)
			cmd_list(cmd, SA);
	}
	else if ((*a)->data > elem2->data && elem2->data < elem3->data && elem3->data > (*a)->data)
		cmd_list(cmd, SA);
	else if ((*a)->data < elem2->data && elem2->data > elem3->data && elem3->data < (*a)->data)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data < elem2->data && elem2->data > elem3->data && elem3->data > (*a)->data)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
	}
	else if ((*a)->data > elem2->data && elem2->data > elem3->data && elem3->data < (*a)->data)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if ((*a)->data > elem2->data && elem2->data < elem3->data && elem3->data < (*a)->data)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
	}
}

int		max_period(t_stack *a, int size)
{
	int		res;

	res = a->data;
	if (a == NULL)
		return (0);
	while (size && a != NULL)
	{
		if (res < a->data)
			res = a->data;
		a = a->next;
		size--;
	}
	return (res);
}

int		min_period(t_stack *a, int size)
{
	int		res;

	res = a->data;
	if (a == NULL)
		return (0);
	while (size && a != NULL)
	{
		if (res > a->data)
			res = a->data;
		a = a->next;
		size--;
	}
	return (res);
}

int		push_next(t_stack *a, char sign, int len, int middle)
{
	t_stack	*tmp;

	tmp = a;
	while (len-- && tmp != NULL)
	{
		if (sign == 'a' && tmp->data < middle)
			return (1);
		if (sign == 'b' && tmp->data > middle)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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

void	sorting_b(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	int		middle;
	int		rotate;
	int		i;
	int		push;

	rotate = 0;
	push = 0;
	i = 0;
	if (param.len <= 3)
	{
		sort_b(b, param.len, cmd);
		return ;
	}
	middle = get_middle_curr(*b, param.len);
	while (push_next(*b, 'b', param.len - i, middle) && i++ < param.len)
	{
		if ((*b)->data > middle)
		{
			cmd_list(cmd, PA);
			push++;
		}
		else
		{
			cmd_list(cmd, RB);
			rotate++;
		}
	}
	i = param.len;
	param.len = push;
	param.pushed = i - push;
	sorting_a(a, b, param, cmd);
	back_b(b, rotate, cmd);
	param.len = i - push;
	param.pushed = push;
	sorting_b(a, b, param, cmd);
	while (push--)
		cmd_list(cmd, PB);
}

void	sorting_a(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	int		middle;
	int		rotate;
	int		i;
	int		push;

	rotate = 0;
	push = 0;
	i = 0;
	if (param.len <= 3)
	{
		sort_all(a, b, param, cmd);
		return ;
	}
	middle = get_middle_curr(*a, param.len);
	while (push_next(*a, 'a', param.len - i, middle) && i++ < param.len)
	{
		if ((*a)->data < middle)
		{
			cmd_list(cmd, PB);
			push++;
		}
		else
		{
			cmd_list(cmd, RA);
			rotate++;
		}
	}
	back_a(a, rotate, cmd);
	i = param.len;
	param.len = i - push;
	param.pushed = push;
	sorting_a(a, b, param, cmd);
	param.len = push;
	param.pushed = i - push;
	sorting_b(a, b, param, cmd);
	while (push--)
		cmd_list(cmd, PA);
}
