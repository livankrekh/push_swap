/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 11:39:19 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/23 11:39:20 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ss(t_stack *a, t_stack *b)
{
	s(a, 'a');
	s(b, 'b');
	return (3);
}

int		rr(t_stack **a, t_stack **b)
{
	r(a, 'b');
	r(b, 'b');
	return (23);
}

int		rrr(t_stack **a, t_stack **b)
{
	reverse(a, 'a');
	reverse(b, 'b');
	return (33);
}

void	cmd_list_dop(t_cmd **tmp, int sign)
{
	if (sign == 1)
		ft_strncpy((*tmp)->data, "sa\n", 3);
	else if (sign == 2)
		ft_strncpy((*tmp)->data, "sb\n", 3);
	else if (sign == 3)
		ft_strncpy((*tmp)->data, "ss\n", 3);
	else if (sign == 11)
		ft_strncpy((*tmp)->data, "pa\n", 3);
	else if (sign == 12)
		ft_strncpy((*tmp)->data, "pb\n", 3);
	else if (sign == 21)
		ft_strncpy((*tmp)->data, "ra\n", 3);
	else if (sign == 22)
		ft_strncpy((*tmp)->data, "rb\n", 3);
	else if (sign == 23)
		ft_strncpy((*tmp)->data, "rr\n", 3);
	else if (sign == 31)
		ft_strncpy((*tmp)->data, "rra\n", 4);
	else if (sign == 32)
		ft_strncpy((*tmp)->data, "rrb\n", 4);
	else if (sign == 33)
		ft_strncpy((*tmp)->data, "rrr\n", 4);
}

void	cmd_list(t_cmd **cmd, int sign)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	tmp2 = (*cmd);
	tmp = (t_cmd*)malloc(sizeof(t_cmd));
	tmp->data = ft_strnew((sign > 30) ? 4 : 3);
	tmp->next = NULL;
	cmd_list_dop(&tmp, sign);
	if (*cmd == NULL)
		*cmd = tmp;
	else
	{
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}
