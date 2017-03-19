/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:01:01 by liabanzh          #+#    #+#             */
/*   Updated: 2017/03/17 19:01:02 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	stack_input(t_stack *a, char **argv, int argc)
{
	int 		i;

	i = 1;
	while (i < argc)
	{
		if (valid(argv[i]) == 0)
			return (0);
		a->data = ft_atoi(argv[i]);
		a->next = (t_stack*)malloc(sizeof(t_stack));
		a = a->next;
		i++;
	}
	a->next = NULL;
	return (1);
}
