/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:57:08 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/22 18:57:10 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		del_dop2(t_cmd **tmp, t_cmd **curr, char *sign)
{
	if (!ft_strcmp(sign, "pa\n"))
	{
		if (!ft_strcmp((*tmp)->data, "pb\n"))
		{
			ft_strclr((*curr)->data);
			ft_strclr((*tmp)->data);
			return (1);
		}
	}
	else if (!ft_strcmp(sign, "pb\n"))
	{
		if (!ft_strcmp((*tmp)->data, "pa\n"))
		{
			ft_strclr((*curr)->data);
			ft_strclr((*tmp)->data);
			return (1);
		}
	}
	return (0);
}

int		del_dop(t_cmd **tmp, t_cmd **curr, char *sign)
{
	if (!ft_strcmp(sign, "rra\n"))
	{
		if (!ft_strcmp((*tmp)->data, "ra\n"))
		{
			ft_strclr((*curr)->data);
			ft_strclr((*tmp)->data);
			return (1);
		}
	}
	else if (!ft_strcmp(sign, "rrb\n"))
	{
		if (!ft_strcmp((*tmp)->data, "rb\n"))
		{
			ft_strclr((*curr)->data);
			ft_strclr((*tmp)->data);
			return (1);
		}
	}
	return (del_dop2(tmp, curr, sign));
}

int		del_elem(t_cmd *curr, char *sign)
{
	t_cmd	*tmp;

	tmp = curr;
	while ((!ft_strcmp(tmp->data, sign) ||
		ft_strlen(tmp->data) == 0) && tmp->next)
		tmp = tmp->next;
	if (!ft_strcmp(sign, "ra\n"))
	{
		if (!ft_strcmp(tmp->data, "rra\n"))
		{
			ft_strclr(curr->data);
			ft_strclr(tmp->data);
			return (1);
		}
	}
	else if (!ft_strcmp(sign, "rb\n"))
	{
		if (!ft_strcmp(tmp->data, "rrb\n"))
		{
			ft_strclr(curr->data);
			ft_strclr(tmp->data);
			return (1);
		}
	}
	return (del_dop(&tmp, &curr, sign));
}

int		optimize(t_cmd *curr)
{
	t_cmd	*next;

	next = curr->next;
	if (next == NULL)
		return (0);
	if ((!ft_strcmp(curr->data, "sa\n") && !ft_strcmp(next->data, "sb\n"))
		|| (!ft_strcmp(curr->data, "sb\n") && !ft_strcmp(next->data, "sa\n")))
	{
		ft_strclr(next->data);
		return ((curr->data[1] = 's'));
	}
	else if ((!ft_strcmp(curr->data, "ra\n") && !ft_strcmp(next->data, "rb\n"))
		|| (!ft_strcmp(curr->data, "rb\n") && !ft_strcmp(next->data, "ra\n")))
	{
		ft_strclr(next->data);
		return ((curr->data[1] = 'r'));
	}
	else if ((!ft_strcmp(curr->data, "rra\n") &&
		!ft_strcmp(next->data, "rrb\n")) ||
		(!ft_strcmp(curr->data, "rrb\n") && !ft_strcmp(next->data, "rra\n")))
	{
		ft_strclr(next->data);
		return ((curr->data[2] = 'r'));
	}
	return (0);
}

void	change_list(t_cmd **cmd)
{
	t_cmd	*tmp;
	int		res;

	tmp = *cmd;
	res = 0;
	while (1)
	{
		if (ft_strnstr(tmp->data, "ra", 2) || ft_strnstr(tmp->data, "rb", 2) ||
			ft_strnstr(tmp->data, "rra", 3) || ft_strnstr(tmp->data, "rrb", 3)
			|| ft_strnstr(tmp->data, "pa", 2) || ft_strnstr(tmp->data, "pb", 2))
			res += del_elem(tmp, tmp->data);
		res += optimize(tmp);
		tmp = tmp->next;
		if (tmp == NULL)
		{
			if (res == 0)
				return ;
			res = 0;
			tmp = *cmd;
		}
	}
}
