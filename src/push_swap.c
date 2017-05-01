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

void	delete_list_cmd(t_cmd **cmd)
{
	t_cmd	*next;
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = next;
	}
	*cmd = NULL;
}

void	print_cmd(t_cmd *cmd)
{
	while (cmd != NULL)
	{
		ft_putstr(cmd->data);
		cmd = cmd->next;
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
	if (stack_input(&a, argv, argc) == 0 || argc < 3)
		return (-1);
	if (is_sorted(a))
		return (1);
	param.len = count(a);
	param.pushed = 0;
	sorting_a(&a, &b, param, &cmd);
	change_list(&cmd);
	print_cmd(cmd);
	delete_list_cmd(&cmd);
	delete_list_a(&a);
	return (0);
}
