/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:35:07 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/17 17:35:09 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_elem(t_cmd *curr, char *sign)
{
	t_cmd	*tmp;

	tmp = curr;
	while (!ft_strcmp(tmp->data, sign) || ft_strlen(tmp->data) == 0)
		tmp = tmp->next;
	if (!ft_strcmp(sign, "ra\n"))
	{
		if (!ft_strcmp(tmp->data, "rra\n"))
		{
			ft_strclr(curr->data);
			ft_strclr(tmp->data);
		}
	}
	else if (!ft_strcmp(sign, "rb\n"))
	{
		if (!ft_strcmp(tmp->data, "rrb\n"))
		{
			ft_strclr(curr->data);
			ft_strclr(tmp->data);
		}
	}
	else if (!ft_strcmp(sign, "rra\n"))
	{
		if (!ft_strcmp(tmp->data, "ra\n"))
		{
			ft_strclr(curr->data);
			ft_strclr(tmp->data);
		}
	}
	else if (!ft_strcmp(sign, "rrb\n"))
	{
		if (!ft_strcmp(tmp->data, "rb\n"))
		{
			ft_strclr(curr->data);
			ft_strclr(tmp->data);
		}
	}
}

void	optimize(t_cmd *curr)
{
	t_cmd	*next;

	next = curr->next;
	if (next == NULL)
		return ;
	if ((!ft_strcmp(curr->data, "sa\n") && !ft_strcmp(next->data, "sb\n"))
		|| (!ft_strcmp(curr->data, "sb\n") && !ft_strcmp(next->data, "sa\n")))
	{
		ft_strclr(next->data);
		curr->data[1] = 's';
	}
	else if ((!ft_strcmp(curr->data, "ra\n") && !ft_strcmp(next->data, "rb\n"))
		|| (!ft_strcmp(curr->data, "rb\n") && !ft_strcmp(next->data, "ra\n")))
	{
		ft_strclr(next->data);
		curr->data[1] = 'r';
	}
	else if ((!ft_strcmp(curr->data, "rra\n") && !ft_strcmp(next->data, "rrb\n"))
		|| (!ft_strcmp(curr->data, "rrb\n") && !ft_strcmp(next->data, "rra\n")))
	{
		ft_strclr(next->data);
		curr->data[2] = 'r';
	}
}

void	change_list(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp != NULL)
	{
		if (ft_strnstr(tmp->data, "ra", 2) || ft_strnstr(tmp->data, "rb", 2) ||
			ft_strnstr(tmp->data, "rra", 3) || ft_strnstr(tmp->data, "rrb", 3))
			del_elem(tmp, tmp->data);
		optimize(tmp);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_inf		param;
	t_cmd		*cmd;

	b = NULL;
	cmd = NULL;
	a = (t_stack*)malloc(sizeof(t_stack));
	if (stack_input(a, argv, argc) == 0 || argc < 3)
		return (-1);
	if (is_sorted(a))
		return (1);
	param.len = count(a);
	param.pushed = 0;
	sorting_a(&a, &b, param, &cmd);
	change_list(&cmd);
	while (cmd != NULL)
	{
		ft_putstr(cmd->data);
		cmd = cmd->next;
	}
	return (0);
}
