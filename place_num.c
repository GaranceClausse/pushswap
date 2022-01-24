/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/24 15:21:33 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
/*
int	place_num(t_stack *stack, int x)
{
	int	i;

	i = 0;
	if (x > stack->tab[stack->start_b])
		i = 0;
	else
	{
		while (x < stack->tab[stack->start_b + i])
			 i++;
	}
	return (i);
}

void	sort_b(t_stack *stack, int x)
{
	int	i;
	int	cpt;
	int	size;

	i = place_num(stack, x);
	cpt = i;
	size = 7;
	if (i == 0)
	{
		printf("i = %d\n", i);
		push_b(stack);
	}
	else if (i == 1)
	{
		printf("i = %d\n", i);

		push_b(stack);
		swap_b(stack);
	}
	else if (i == size)
	{
		printf("i = %d\n", i);
		push_b(stack);
		rotate_b(stack);
	}
	else if (i > 3 && i < (size / 2))
	{
		while (i > 0)
		{
			printf("i = %d\n", i);
			rotate_b(stack);
			i--;
		}
		push_b(stack);
		i = cpt;
		while (i > 0)
		{
			printf("i = %d\n", i);
			rrotate_b(stack);
			i--;
		}
	}
	else if (i > 3 && i >= (size / 2))
	{
		i = cpt;
		cpt = size - i;
		while (cpt > 0)
		{
			rrotate_b(stack);
			cpt--;
		}
		cpt = size - i + 1;
		while (cpt > 0)
		{
			push_b(stack);
			cpt--;
		}
	}
}*/

static void	ft_afficher(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->tab[i])
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}
		
/*
void	push_swap(t_stack *stack)
{
	int	i;
//	int	j;

	i = stack->start_b;
	printf("start_b dans push_swap =  %d\n", i);
//	push_b(stack);
	if (stack_sorted(stack) == 1)
	{
		printf("victoryy\n");
		return ;
	}
	while (stack_sorted(stack) == 0)
	{
	//	if (stack->tab[0] < stack->tab[stack->start_b])
	//	{
			if (stack->tab[0] > stack->tab[stack->start_b - 1])
				rotate_a(stack);
			if (stack->tab[0] > stack->tab[1])
				swap_a(stack);
//		}
//		else
	//	{
			sort_b(stack, stack->tab[0]);
		   printf("tab[0] = %d, tab[1] = %d, tab[2] = %d, tab[3] = %d, tab[4] = %d, tab[5] = %d, tab[6] = %d, tab[7] = %d\n", stack->tab[0], stack->tab[1],  stack->tab[2], stack->tab[3],  stack->tab[4], stack->tab[5],  stack->tab[6], stack->tab[7]);
	//	}
	}	
	ft_afficher(stack);
}*/

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
	printf("val = %d\n", val);
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
	while(stack->tab[i++] != val)
		pos++;
	printf("pos = %d\n", pos);
	return (pos);
}

void	push_swap(t_stack *stack)
{
	int	small_pos;
	int	small_val;
	int	i;


	i = 0;
	while (i < 2)
	{
		small_pos = get_small_pos(stack);
		small_val = get_small_val(stack);
		if (small_pos == 0)
			push_b(stack);
		else if (small_pos > (stack->start_b / 2))
		{
			printf(" stack->tab[0] = %d\n", stack->tab[0] );
			while(small_val != stack->tab[0])
				rrotate_a(stack);
		}
		else
		{
			while ( small_val != stack->tab[0])
				rotate_a(stack);
		}
		push_b(stack);
		i++;
	}
	sort_three(stack);
	push_a(stack);
	push_a(stack);
}
/*	while (stack_sorted(stack) == 0)
	{
		while (stack->tab[0] < get_median(stack))
				push_b(stack);
		if (stack->tab[0] >stack->tab[1])
			swap_a(stack);
		else if (stack->tab[0] > stack->tab[stack->start_b - 1])
			rotate_a(stack);
		if (stack->size - stack->start_b == 1)
		{
			sort_three(stack);
			push_a(stack);
			push_a(stack);
			if (stack->tab[0] >stack->tab[1])
				swap_a(stack);
			break ;
		}
	}*/
		


void	sort_three(t_stack *stack)
{
	if (stack_sorted(stack) == 1)
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
	else if (stack_sorted(stack) == 0)
		rrotate_a(stack);
}

void	sort_five(t_stack *stack)
{
	if (stack_sorted(stack) == 1)
		return ;
	if (stack_reverse_sorted(stack) == 1)
	{
		rrotate_a(stack);
		push_b(stack);
		rrotate_a(stack);
		push_b(stack);
		sort_three(stack);
		push_a(stack);
		push_a(stack);
	}
	else
	{
		push_swap(stack);
		ft_afficher(stack);
	}
}
