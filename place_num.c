/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/26 18:11:54 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_small(t_stack *stack)
{
	int	small_pos;
	int	small_val;
	int	i;


	i = 0;
	while (i <= stack->size - 3)
	{
		small_pos = get_small_pos(stack);
		small_val = get_small_val(stack);
		if (small_pos == 0)
			push_b(stack);
		else if (small_pos > (stack->start_b / 2))
		{
			while(small_val != stack->tab[0])
				rrotate_a(stack);
			push_b(stack);
		}
		else
		{
			while ( small_val != stack->tab[0])
				rotate_a(stack);
			push_b(stack);

		}
		i++;
	}
	sort_three(stack);
	while (i > 0)
	{
		push_a(stack);
		i--;
	}
}
/*
void	push_swap_fifty(t_stack *stack)
{
	int	small_pos;
	int	small_val;
	int	i;


	i = 0;
	while (i < stack->size- 3)
	{
		small_pos = get_small_pos(stack);
		small_val = get_small_val(stack);
		if (small_pos == 0)
			push_b(stack);
		else if (small_pos > ((stack->size + 1) / 4))
		{
			while(small_val != stack->tab[0])
				rrotate_a(stack);
			push_b(stack);
		}
		else
		{
			while ( small_val != stack->tab[0])
				rotate_a(stack);
			push_b(stack);
		}
		i++;
	}
	sort_three(stack);
	while (i > 0)
	{
		push_a(stack);
		i--;
	}
}*/

void	push_swap_hundred(t_stack *stack)
{
	int	big_pos;
	int	big_val;
	int	i;
	int	len_b;


	i = stack->start_b;
	len_b = (stack->size + 1) / 2;
	while (i <= stack->size)
	{
		big_pos = get_big_pos(stack);
		big_val = get_big_val(stack);
		if (big_pos <= len_b / 2)
		{
			while(big_val != stack->tab[stack->start_b])
			{
				rotate_b(stack);
			}
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
		i++;
	}
	i = stack->size;
	while (i >= stack->size / 2)
	{
		rrotate_a(stack);
		push_b(stack);
		i--;
	}
	len_b = (stack->size + 1) / 2;
	while (i < stack->size)
	{
		big_pos = get_big_pos(stack);
		big_val = get_big_val(stack);
		if (big_pos > ((len_b / 2)))
		{
			while(big_val != stack->tab[stack->start_b])
			{
				rrotate_b(stack);
				
			}
			push_a(stack);
			len_b--;
		}
		else
		{
			while (big_val != stack->tab[stack->start_b])
			{
				rotate_b(stack);
			}


			push_a(stack);
			len_b--;
		}
		i++;
	}
}

void	push_swap_fivehundred(t_stack *stack)
{

	int	i;
	int	median;
	int	bigquartil;
	int	quartil;


	bigquartil = get_bigquartil(stack);
	quartil = get_quartil(stack);		
	median = get_median(stack);
	sort_b(stack, 1);
	i = 0;
	while (stack->tab[stack->start_b - 1] != bigquartil)
	{
		if (stack->tab[0] > bigquartil)
		{
			push_b(stack);
		
		}
		else
		{
			rrotate_a(stack);
		}
		
		i++;
	}
	sort_b(stack, 1);
	i = 0;
	while (stack->tab[0] != median)
	{
		if (stack->tab[0] < median && stack->tab[0] >= quartil)
		{
			push_b(stack);
		
		}
		else
		{
			rotate_a(stack);
		}
		i++;
	}
	sort_b(stack, 1);
	i = 0;
	while (stack->tab[0] == quartil && stack->tab[stack->start_b - 1] < quartil)
	{
		rrotate_a(stack);
		push_b(stack);
		i++;
	}
	sort_b(stack, 1);

}


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

void	push_swap_hundred_init(t_stack *stack)
{
	push_and_rotate_median(stack, 0);
	push_swap_hundred(stack);
}

void	push_swap_fivehundred_init(t_stack *stack)
{
	push_and_rotate_median(stack, 1);
	push_swap_fivehundred(stack);
}

