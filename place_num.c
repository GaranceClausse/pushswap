/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/24 11:12:58 by gclausse         ###   ########.fr       */
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
		printf("victoryy\n");
		return ;
	}
	while (stack_sorted(stack) == 0)
	{
		printf("stack not sorted\n ");
		if (stack->size < stack->start_b)
			push_b(stack);
		printf("tab[0] = %d\n", stack->tab[0]);
		printf("tab[0start_b] = %d\n", stack->tab[stack->start_b]);
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
