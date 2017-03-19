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

int		valid(char *n)
{
	int			i;
	long long	numb;

	i = n[0] == '-' ? 1 : 0;
	while (n[i] != '\0')
	{
		if (!ft_isdigit(n[i]))
		{
			write(1, "Invalid input! Invalid argument - ", 34);
			ft_putstr(n);
			return (0);
		}
		i++;
	}
	if (ft_strlen((n[0] == '-') ? n + 1 : n) >= 10 ||
		ft_atoi_long(n) > MAX_INT || ft_atoi_long(n) < MIN_INT)
	{
		write(1, "Argument larger then MAX_INT! Invalid argument - ", 49);
		ft_putstr(n);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*b;

	i = 0;
	a = (t_stack*)malloc(sizeof(t_stack));
	b = (t_stack*)malloc(sizeof(t_stack));
	if (stack_input(a, argv, argc) == 0)
		return (-1);
	RRA;
	printf("CURRENT = %d\n", a->data);
	return (0);
}
