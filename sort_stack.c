/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:28:04 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/28 16:32:48 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_rotate_median(t_stack *stack)
{
	int	i;
	int	median;
	int	bigquartil;

	i = 0;
	median = get_median(stack);
	bigquartil = get_bigquartil(stack);
	while (i <= stack->size)
	{
		if (stack->tab[0] >= median && stack->tab[0] <= bigquartil)
			push_b(stack);
		else 
			rotate_a(stack);
		i++;
	}
}

void	push_and_rotate_quartil(t_stack *stack)
{
	int	median;
	int	quartil;

	median = get_median(stack);
	quartil = get_quartil(stack);
	while (stack->tab[0] != median)
	{
		if (stack->tab[0] < median && stack->tab[0] >= quartil)
			push_b(stack);
		else if (stack->tab[0] != median)
			rotate_a(stack);
	}
}

void	push_and_rotate_bigquartil(t_stack *stack)
{
	int	bigquartil;


	bigquartil = get_bigquartil(stack);
	while (stack->tab[stack->start_b - 1] != bigquartil)
	{
		if (stack->tab[0] >= bigquartil)
			push_b(stack);
		else if (stack->tab[stack->start_b - 1] != bigquartil)
			rrotate_a(stack);
	}
	if (stack->tab[0] > bigquartil)
		push_b(stack);
}

void	push_and_rotate_bigquartil_eighth(t_stack *stack)
{
	int	bigquartil;


	bigquartil = get_bigquartil(stack);
	while (stack->tab[stack->start_b - 1] != bigquartil)
	{
		if (stack->tab[0] >= bigquartil && stack->tab[0] <= get_eighth(stack))
			push_b(stack);
		else 
			rrotate_a(stack);
	}
	if (stack->tab[0] > bigquartil && stack->tab[0] <= get_eighth(stack))
		push_b(stack);
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
			while(big_val != stack->tab[stack->start_b])
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

