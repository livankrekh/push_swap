/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:25:11 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/22 19:25:13 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all_finish(t_stack **a, t_stack **b, t_cmd **cmd, int a_check)
{
	if (a_check == 4)
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

void	sort_all_dop(t_stack **a, t_stack **b, t_cmd **cmd, int a_check)
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
	else
		sort_all_finish(a, b, cmd, a_check);
}

void	sort_all_dop3(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 1 && param.pushed == 5)
	{
		cmd_list(cmd, SS);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
	}
	else if (param.len == 2 && param.pushed == 1)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if (param.len == 2 && param.pushed == 3)
	{
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SA);
	}
	else
		sort_d(a, b, param, cmd);
}

void	sort_all_dop2(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 1 && param.pushed == 2)
	{
		cmd_list(cmd, RB);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRB);
		cmd_list(cmd, SB);
	}
	else if (param.len == 1 && param.pushed == 3)
	{
		cmd_list(cmd, RB);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRB);
	}
	else if (param.len == 1 && param.pushed == 4)
	{
		cmd_list(cmd, SS);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRB);
		cmd_list(cmd, SB);
	}
	else
		sort_all_dop3(a, b, param, cmd);
}

void	sort_all(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (check_a(*a, param.len) == check_b(*b, param.pushed))
		sort_all_dop(a, b, cmd, check_a(*a, param.len));
	else if (check_a(*a, param.len) != 0 && check_b(*b, param.pushed) != 0)
	{
		param.len = check_a(*a, param.len);
		param.pushed = check_b(*b, param.pushed);
		sort_all_dop2(a, b, param, cmd);
	}
	else if (check_a(*a, param.len) == 0)
	{
		if (count(*b) <= 3)
			simple_sort_b(b, param.pushed, cmd);
		else
			sort_b(b, param.pushed, cmd);
	}
	else if (check_b(*b, param.pushed) == 0)
	{
		if (count(*a) <= 3)
			simple_sort_a(a, param.len, cmd);
		else
			sort(a, param.len, cmd);
	}
}
