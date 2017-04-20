/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:23:28 by liabanzh          #+#    #+#             */
/*   Updated: 2017/04/15 16:23:30 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	go_cmd(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		SA;
	else if (!ft_strcmp(cmd, "sb"))
		SB;
	else if (!ft_strcmp(cmd, "ss"))
		SS;
	else if (!ft_strcmp(cmd, "pa"))
		PA;
	else if (!ft_strcmp(cmd, "pb"))
		PB;
	else if (!ft_strcmp(cmd, "ra"))
		RA;
	else if (!ft_strcmp(cmd, "rb"))
		RB;
	else if (!ft_strcmp(cmd, "rr"))
		RR;
	else if (!ft_strcmp(cmd, "rra"))
		RRA;
	else if (!ft_strcmp(cmd, "rrb"))
		RRB;
	else if (!ft_strcmp(cmd, "rrr"))
		RRR;
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	b = NULL;
	cmd = ft_strnew(4);
	a = (t_stack*)malloc(sizeof(t_stack));
	if (stack_input(a, argv, argc) == 0 || argc < 3)
		return (-1);
	while (get_next_line(0, &cmd))
	{
		if (go_cmd(&a, &b, cmd) == 0)
			return (-1);
	}
	if (is_sorted(a) && b == NULL)
		ft_putstr("\033[32mOK\033[0m\n");
	else
		ft_putstr("\033[31mKO\033[0m\n");
	return (0);
}
