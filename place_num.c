/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/08 15:08:21 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack_sorted(stack) == 1)
		return ;
	if (stack->size == 1)
	{
		rotate_a(stack);
		return ;
	}
	if (stack->tab[0] > stack->tab[1])
	{
		if (stack->tab[1] > stack->tab[2] || (stack->tab[0] > stack->tab[1]
				&& stack->tab[0] > stack->tab[2]))
			rotate_a(stack);
		if (stack->tab[0] > stack->tab[1])
			swap_a(stack);
	}
	else if ((stack->tab[2] > stack->tab[0]))
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack_sorted(stack) == 0)
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
	int	*tab;
	int	size;

	size = (stack->size + 1);
	tab = get_tab(stack);
	push_and_rotate_first(stack, tab[(size / 4) * 3], tab[size / 2]);
	sort_b(stack);
	push_and_rrotate(stack, tab[(size / 8 + 1) * 7], tab[(size / 4) * 3]);
	sort_b(stack);
	push_and_rotate(stack, tab[size / 4], tab[size / 2]);
	sort_b(stack);
	push_and_rrotate(stack, get_biggest(stack) + 1, tab[(size / 8 + 1) * 7]);
	sort_b(stack);
	push_and_rotate(stack, tab[size / 8], tab[size / 4]);
	sort_b(stack);
	push_and_rotate_last(stack);
	sort_b(stack);
	free (tab);
}

void	push_swap_fivehundred(t_stack *stack)
{
	int	*tab;
	int	tenth;

	tab = get_tab(stack);
	tenth = (stack->size + 1) / 10;
	push_and_rotate_first(stack, tab[tenth * 5], tab[tenth * 4]);
	sort_b(stack);
	push_and_rrotate(stack, tab[tenth * 6], tab[tenth * 5]);
	sort_b(stack);
	push_and_rotate(stack, tab[tenth * 3], tab[tenth * 4]);
	sort_b(stack);
	push_and_rrotate(stack, tab[tenth * 8], tab[tenth * 6]);
	sort_b(stack);
	push_and_rotate(stack, tab[tenth * 2], tab[tenth * 3]);
	sort_b(stack);
	push_and_rrotate(stack, get_biggest(stack) + 1, tab[tenth * 8]);
	sort_b(stack);
	push_and_rotate(stack, tab[tenth], tab[tenth * 2]);
	sort_b(stack);
	push_and_rotate_last(stack);
	sort_b(stack);
	free(tab);
}
