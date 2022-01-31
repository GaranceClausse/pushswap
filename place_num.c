/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/31 18:13:44 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack_a_sorted(stack) == 1)
		return ;
	if (stack->tab[0] > stack->tab[1])
	{
		if (stack->tab[1] > stack->tab[2] || (stack->tab[0] > stack->tab[1]
				&& stack->tab[0] > stack->tab[2]))
			rotate_a(stack);
		if (stack->tab[0] > stack->tab[1])
			swap_a(stack);
	}
	else if (stack->tab[2] > stack->tab[0])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack_a_sorted(stack) == 0)
		rrotate_a(stack);
}

void	push_swap_small(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->size - 3)
	{
		if (get_small_pos(stack) == 0)
			push_b(stack);
		else if (get_small_pos(stack) > (stack->start_b / 2))
		{
			while (stack->tab[0] != get_small_val(stack))
				rrotate_a(stack);
			push_b(stack);
		}
		else
		{
			while (stack->tab[0] != get_small_val(stack))
				rotate_a(stack);
			push_b(stack);
		}
		i++;
	}
	sort_three(stack);
	while (stack->start_b <= stack->size)
		push_a(stack);
}

void	push_swap_hundred(t_stack *stack)
{
	push_and_rotate_median(stack);
	sort_b(stack);
	push_and_rotate_bigquartil_eighth(stack);
	sort_b(stack);
	push_and_rotate_quartil(stack);
	sort_b(stack);
	push_and_rotate_small_eighth(stack);
	sort_b(stack);
	push_and_rotate_quartil_smalleighth(stack);
	sort_b(stack);
	while (stack->tab[stack->start_b - 1] != get_biggest(stack))
		rrotate_a(stack);
	while (stack->tab[0] != get_smalleighth(stack))
		push_b(stack);
	sort_b(stack);
}

void	push_swap_fivehundred(t_stack *stack)
{
	push_and_rotate_200_250(stack);
	sort_b(stack);
	push_and_rotate_250_300(stack);
	sort_b(stack);
	push_and_rotate_150_200(stack);
	sort_b(stack);
	push_and_rotate_300_400(stack);
	sort_b(stack);
	push_and_rotate_100_150(stack);
	sort_b(stack);
	push_and_rotate_400_500(stack);
	sort_b(stack);
	push_and_rotate_50_100(stack);
	sort_b(stack);
	push_and_rotate_0_50(stack);
	sort_b(stack);
}
