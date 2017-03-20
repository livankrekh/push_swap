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

int 	dop(char *arg, t_stack **a)
{
	char	**tmp;
	int 	i;

	i = 0;
	tmp = ft_strsplit(arg, ' ');
	while (tmp[i] != NULL)
	{
		if (valid(tmp[i]) == 0)
			return (0);
		(*a)->data = ft_atoi(tmp[i]);
		(*a)->next = NULL;
		i++;
		if (tmp[i] != NULL)
		{
			(*a)->next = (t_stack*)malloc(sizeof(t_stack));
			(*a) = (*a)->next;
		}
	}
	return (1);
}

int 	stack_input(t_stack *a, char **argv, int argc)
{
	int 		i;

	i = 1;
	if (argc == 2)
	{
		if (dop(argv[1], &a) == 0)
			return (0);
	}
	while (i < argc && argc != 2)
	{
		if (valid(argv[i]) == 0)
			return (0);
		a->data = ft_atoi(argv[i]);
		a->next = NULL;
		i++;
		if (i < argc)
		{
			a->next = (t_stack*)malloc(sizeof(t_stack));
			a = a->next;
		}
	}
	return (1);
}
