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

int		sorting_b_dop(t_stack **a, t_stack **b, int middle, t_cmd **cmd)
{
	int		push;

	push = 0;
	if ((*b)->data > middle)
	{
		cmd_list(cmd, PA);
		push++;
	}
	else
		cmd_list(cmd, RB);
	return (push);
}

void	sorting_b(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	int		middle;
	int		rotate;
	int		i;
	int		push;

	push = 0;
	i = 0;
	if (param.len <= 3)
		return (sort_b(b, param.len, cmd));
	middle = get_middle_curr(*b, param.len);
	while (push_next(*b, 'b', param.len - i, middle) && i++ < param.len)
		push += sorting_b_dop(a, b, middle, cmd);
	rotate = i - push;
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

int		sorting_a_dop(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	int		middle;
	int		rotate;
	int		push;
	int		i;

	push = 0;
	rotate = 0;
	i = 0;
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
	return (push);
}

void	sorting_a(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	int		i;
	int		push;

	if (param.len <= 3)
		return (sort_all(a, b, param, cmd));
	push = sorting_a_dop(a, b, param, cmd);
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
