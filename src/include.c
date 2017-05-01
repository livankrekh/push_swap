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

int		return_print(void)
{
	ft_putstr("Error\n");
	return (0);
}

int		valid(char *n, char **argv, int argc, int index)
{
	int		i;

	i = n[0] == '-' ? 1 : 0;
	if (ft_strlen(n) == 0)
		return (0);
	while (n[i] != '\0')
	{
		if (!ft_isdigit(n[i]))
			return (return_print());
		i++;
	}
	if (ft_strlen((n[0] == '-') ? n + 1 : n) >= 10 ||
		ft_atoi_long(n) > MAX_INT || ft_atoi_long(n) < MIN_INT)
		return (return_print());
	while (argc > 0)
	{
		if (ft_atoi(n) == ft_atoi(argv[--argc]) && argc != index && argc != 0)
			return (return_print());
	}
	return (1);
}

int		stack_input(t_stack **stack, char **argv, int argc)
{
	int			i;
	t_stack		*a;

	i = 1;
	a = *stack;
	if (argc == 2)
		return (0);
	while (i < argc && argc != 2)
	{
		if (valid(argv[i], argv, argc, i) == 0)
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
