/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:28:04 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/31 17:24:48 by gclausse         ###   ########.fr       */
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

void	push_and_rotate_200_250(t_stack *stack)
{
	int	median;
	int	fourty;
	int	i;

	i = 0;
	median = get_median(stack);
	fourty = get_fourtyth(stack);
	while (i <= stack->size + 1)
	{
		if (stack->tab[0] <= median && stack->tab[0] >= fourty)
			push_b(stack);
		else
			rotate_a(stack);
		i++;
	}
}

void	push_and_rotate_250_300(t_stack *stack)
{
	int	sixty;
	int	median;
	
	median = get_median(stack);
	sixty = get_sixtyth(stack);
	while (stack->tab[stack->start_b - 1] != median)
	{
		if (stack->tab[0] > median && stack->tab[0] <= sixty)
			push_b(stack);
		else if (stack->tab[stack->start_b - 1] != median)
			rrotate_a(stack);
	}
	if (stack->tab[0] > median && stack->tab[0] <= sixty)
			push_b(stack);

}

void	push_and_rotate_150_200(t_stack *stack)
{
	int	thirty;
	int	fourty;

	thirty = get_thirtyth(stack);
	fourty = get_fourtyth(stack);
	while (stack->tab[0] != fourty)
	{
		if (stack->tab[0] < fourty && stack->tab[0] >= thirty)
			push_b(stack);
		else
			rotate_a(stack);
	}
}

void	push_and_rotate_300_400(t_stack *stack)
{
	int	sixty;
	int	eighty;
	
	sixty = get_sixtyth(stack);
	eighty = get_eightyth(stack);
	while (stack->tab[stack->start_b - 1] != sixty)
	{
		if (stack->tab[0] > sixty && stack->tab[0] <= eighty)
			push_b(stack);
		else if (stack->tab[stack->start_b - 1] != sixty)
			rrotate_a(stack);
	}
	if (stack->tab[0] <= eighty && stack->tab[0] > sixty)
		push_b(stack);

}


void	push_and_rotate_100_150(t_stack *stack)
{
	int	thirty;
	int	twenty;
	
	twenty = get_tentyth(stack);
	thirty = get_thirtyth(stack);
	while (stack->tab[0] != thirty)
	{
		if (stack->tab[0] < thirty && stack->tab[0] >= twenty)
			push_b(stack);
		else
			rotate_a(stack);
	}
}

void	push_and_rotate_400_500(t_stack *stack)
{
	int	eighty;
	
	eighty = get_eightyth(stack);
	while (stack->tab[stack->start_b - 1] != eighty)
	{
		if (stack->tab[0] > eighty)
			push_b(stack);
		else if (stack->tab[stack->start_b - 1] != eighty)
			rrotate_a(stack);
	}
	if (stack->tab[0] > eighty)
		push_b(stack);

}

void	push_and_rotate_50_100(t_stack *stack)
{
	int	twenty;
	int	ten;
	
	twenty = get_tentyth(stack);
	ten = get_tenth(stack);
	while (stack->tab[0] != twenty)
	{
		if (stack->tab[0] < twenty && stack->tab[0] >= ten)
			push_b(stack);
		else
			rotate_a(stack);
	}
}

void	push_and_rotate_0_50(t_stack *stack)
{
	while (stack->tab[stack->start_b - 1] != get_biggest(stack))
	{
		rrotate_a(stack);
		push_b(stack);
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

