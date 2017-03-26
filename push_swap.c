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

int		main(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*b;

	i = 0;
	b = NULL;
	a = (t_stack*)malloc(sizeof(t_stack));
	if (stack_input(a, argv, argc) == 0)
		return (-1);
	sorting(&a, &b, min_a(a), max_a(a));
	//print_stack(a, b);
	return (0);
}
