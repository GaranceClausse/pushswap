/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/21 19:00:50 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	printf("segv\n");
	while( i <= stack->size)
	{
		printf("stack->tab[i] = %d\n", stack->tab[i]);
		printf("stack->tab[i + 1] = %d\n", stack->tab[i + 1]);

		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		else
			i++;
	}
	printf("i = %d\n", i);
	printf("size = %d\n", stack->size);
	return (1);
}

int	place_num(t_stack *stack, int x)
{
	int	i;

	if (x > stack->tab[stack->start_b])
		i = 1;
	while (x < stack->tab[stack->start_b])
		 i++;
	return (i);
}

void	sort_b(t_stack *stack, int x)
{
	int	i;
	int	cpt;
	int	size;

	i = place_num(stack, x);
	cpt = i;
	size = stack->size - stack->start_b;
	if (i == 1)
		push_b(stack);
	else if (i == 2)
	{
		push_b(stack);
		swap_a(stack);
	}
	else if (i == size + 1)
	{
		push_a(stack);
		rotate_b(stack);
	}
	else if (i >= 3 && i <= (size / 2))
	{
		while (i > 0)
		{
			rotate_b(stack);
			i--;
		}
		push_a(stack);
		i = cpt;
		while (i > 0)
		{
			rrotate_b(stack);
			i--;
		}
	}
	else if (i >= 3 && i > (size / 2))
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
			push_a(stack);
			cpt--;
		}
	}
}

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
		

void	push_swap(t_stack *stack)
{
	int	i;

	i = stack->start_b;
	printf("start_b dans push_swap =  %d\n", i);
//	push_b(stack);
	if (stack_sorted(stack) == 1)
	{
		printf("victoryy");
		return ;
	}
	if (stack_sorted(stack) == 0)
	{
		printf("stack not sorted\n");
		if(stack->tab[0] < stack->tab[stack->start_b])
		{
			if (stack->tab[0] > stack->tab[stack->size])
				rotate_a(stack);
			if (stack->tab[0] > stack->tab[1])
				swap_a(stack);
		}
		else
		{
		   printf("on est la\n");
		   sort_b(stack, stack->tab[0]);
		}

	}
	while (stack->tab[i])
	{
		printf("ici?");
		push_b(stack);
		i++;
	}
	ft_afficher(stack);
}
