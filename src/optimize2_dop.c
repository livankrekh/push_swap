/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 13:56:54 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/23 13:56:56 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_all_dop8(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 5 && param.pushed == 2)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SB);
	}
	else if (param.len == 5 && param.pushed == 3)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
	}
	else if (param.len == 5 && param.pushed == 4)
	{
		cmd_list(cmd, SS);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SB);
	}
}

void	sort_all_dop7(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 4 && param.pushed == 3)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SA);
	}
	else if (param.len == 4 && param.pushed == 5)
	{
		cmd_list(cmd, SS);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SA);
	}
	else if (param.len == 5 && param.pushed == 1)
	{
		cmd_list(cmd, SS);
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
	}
	else
		sort_all_dop8(a, b, param, cmd);
}

void	sort_all_dop6(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 3 && param.pushed == 5)
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
	}
	else if (param.len == 4 && param.pushed == 1)
	{
		cmd_list(cmd, SS);
		cmd_list(cmd, RA);
		cmd_list(cmd, SA);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SA);
	}
	else if (param.len == 4 && param.pushed == 2)
	{
		cmd_list(cmd, SA);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SS);
	}
	else
		sort_all_dop7(a, b, param, cmd);
}

void	sort_all_dop5(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 3 && param.pushed == 1)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRA);
	}
	else if (param.len == 3 && param.pushed == 2)
	{
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SB);
	}
	else if (param.len == 3 && param.pushed == 4)
	{
		cmd_list(cmd, SB);
		cmd_list(cmd, RR);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SB);
	}
	else
		sort_all_dop6(a, b, param, cmd);
}

void	sort_d(t_stack **a, t_stack **b, t_inf param, t_cmd **cmd)
{
	if (param.len == 2 && param.pushed == 4)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SS);
		cmd_list(cmd, RB);
		cmd_list(cmd, SB);
		cmd_list(cmd, RRR);
		cmd_list(cmd, SS);
	}
	else if (param.len == 2 && param.pushed == 5)
	{
		cmd_list(cmd, RA);
		cmd_list(cmd, SS);
		cmd_list(cmd, RB);
		cmd_list(cmd, RRA);
		cmd_list(cmd, SS);
		cmd_list(cmd, RRB);
	}
	else
		sort_all_dop5(a, b, param, cmd);
}
