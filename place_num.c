/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/31 17:24:59 by gclausse         ###   ########.fr       */
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

void	push_swap_hundred(t_stack *stack)
{
	int	big_pos;
	int	big_val;
	int	len_b;


	len_b = (stack->size - stack->start_b);
	while (stack->start_b <= stack->size)
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
	}
	while (stack->tab[stack->start_b - 1] != get_biggest(stack))
	{
		rrotate_a(stack);
		if ( stack->tab[0] != get_biggest(stack))
			push_b(stack);
	}
//	rotate_a(stack);
	len_b = (stack->size - stack->start_b);
	while (stack->start_b <= stack->size)
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
	}
}*/

void	push_swap_hundred(t_stack *stack)
{
	push_and_rotate_median(stack);
	sort_b(stack);
	push_and_rotate_bigquartil_eighth(stack);
	sort_b(stack);
	push_and_rotate_quartil(stack);
	sort_b(stack);
	while(stack->tab[stack->start_b - 1] != get_eighth(stack))
	{
	//	printf("eighth = %d\n", get_eighth(stack));
		rrotate_a(stack);
		if (stack->tab[0] > get_eighth(stack))
			push_b(stack);
	}
	sort_b(stack);
	while (stack->tab[0] != get_quartil(stack))
	{
		if (stack->tab[0] >= get_smalleighth(stack) && stack->tab[0] < get_quartil(stack))
		{
			push_b(stack);
	//		printf("eighth = %d\n", get_eighth(stack));
	//		printf("tab[0] = %d\n", stack->tab[0]);


		}
		else if( stack->tab[0] != get_quartil(stack))
			rotate_a(stack);
	}
//	printf("start[b] == %d, %d\n", stack->start_b, stack->tab[stack->start_b]);
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
