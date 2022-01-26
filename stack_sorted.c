/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:11:25 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/26 17:41:27 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_a_sorted(t_stack *stack)
{
	int	i;
	int	cpt;

	i = 1;
	cpt = 1;
	while (i < stack->start_b - 1)
	{
		if (stack->tab[i] > stack->tab[i - 1])
		{
			i++;
			cpt++;
		}
		else
			i++;
	}
	if (cpt != i)
		return (0);
	return (1);
}

int	check_a(t_stack *stack, int begin, int stop)
{
	int	i;

	i = 0;
	while ( i < stack->start_b)
	{
		if (stack->tab[i] < begin && stack->tab[i] >= stop)
			return (0);
		i++;
	}
	return (1);
}

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while( i < stack->size)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	stack_reverse_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while( i < stack->size)
	{
		if (stack->tab[i] < stack->tab[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}
