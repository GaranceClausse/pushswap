/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:10:02 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/26 14:10:35 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small_val(t_stack *stack)
{
	int	i;
	int	val;

	i = 0;
	val = stack->tab[0];
	while (i < stack->start_b)
	{
		if (stack->tab[i] < val)
			val = stack->tab[i];
		i++;
	}
	return (val);
}

int	get_small_pos(t_stack *stack)
{
	int	i;
	int	val;
	int	pos;

	i = 0;
	pos = 0;
	val = get_small_val(stack);
	while(stack->tab[i] != val)
	{
		pos++;
		i++;
	}
	return (pos);
}

int	get_big_val(t_stack *stack)
{
	int	i;
	int	val;

	i = stack->start_b;
	val = stack->tab[i];
	while (i <= stack->size)
	{
		if (stack->tab[i] > val)
			val = stack->tab[i];
		i++;
	}
	return (val);
}

int	get_big_pos(t_stack *stack)
{
	int	i;
	int	val;
	int	pos;

	i = stack->start_b;
	pos = 0;
	val = get_big_val(stack);
//	if (stack->tab[i])
//	{
		while(stack->tab[i] != val)
		{
			pos++;
			i++;
		}
//	}
	return (pos);
}
