/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:28:04 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/28 14:51:07 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_rotate_median(t_stack *stack, int bigstack)
{
	int	i;
	int	median;
	int	bigquartil;

	i = 0;
	median = get_median(stack);
	bigquartil = get_bigquartil(stack);
	while (i <= stack->size)
	{
		if (bigstack == 0)
		{
			if (stack->tab[0] >= median)
				push_b(stack);
			else
				rotate_a(stack);
		}
		else
		{
			if (stack->tab[0] >= median && stack->tab[0] <= bigquartil)
				push_b(stack);
			else 
				rotate_a(stack);
		}
		i++;
	}
}

void	sort_b(t_stack *stack, int bigstack)
{
	int	len_b;
	int	big_pos;
	int	big_val;

	if (bigstack == 1)
		len_b = (stack->size - stack->start_b);
	else
		len_b = (stack->size - stack->start_b);
	while (stack->start_b <= stack->size)
	{
		big_pos = get_big_pos(stack);
		big_val = get_big_val(stack);
	//	printf("big_val = %d\n", big_val);
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

