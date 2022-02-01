/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:28:04 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/01 13:50:03 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_rotate_first(t_stack *stack, int start, int stop)
{
	int	i;

	i = 0;
	while (i <= stack->size)
	{
		if (stack->tab[0] <= start && stack->tab[0] >= stop)
			push_b(stack);
		else
			rotate_a(stack);
		i++;
	}
}

void	push_and_rotate(t_stack *stack, int start, int stop)
{
	while (stack->tab[0] != stop)
	{
		if (stack->tab[0] < stop && stack->tab[0] >= start)
			push_b(stack);
		else if (stack->tab[0] != stop)
			rotate_a(stack);
	}
}

void	push_and_rrotate(t_stack *stack, int start, int stop)
{
	while (stack->tab[stack->start_b - 1] != stop)
	{
		if (stack->tab[0] >= stop && stack->tab[0] <= start)
			push_b(stack);
		else if (stack->tab[stack->start_b - 1] != stop)
			rrotate_a(stack);
	}
	if (stack->tab[0] > stop && stack->tab[0] <= start)
		push_b(stack);
}

void	push_and_rotate_last(t_stack *stack)
{
	while (stack->tab[stack->start_b - 1] != get_biggest(stack))
	{
		rrotate_a(stack);
		push_b(stack);
	}
}

void	sort_b(t_stack *stack)
{
	int	len_b;
	int	big_pos;
	int	big_val;

	len_b = (stack->size - stack->start_b);
	while (stack->start_b <= stack->size)
	{
		big_pos = get_big_pos(stack);
		big_val = get_big_val(stack);
		if (big_pos <= len_b / 2)
		{
			while (big_val != stack->tab[stack->start_b])
				rotate_b(stack);
			push_a(stack);
			len_b--;
		}
		else
		{
			while (big_val != stack->tab[stack->start_b])
				rrotate_b(stack);
			push_a(stack);
			len_b--;
		}
	}
}
