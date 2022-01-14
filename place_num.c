/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/14 12:39:42 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack->tab[i] < stack->tab[i + 1] && stack->tab[i])
		i++;
	if (i == stack->tab[stack->size])
		return (1);
	else
		return (0);
}
/*
int	place_num(t_stack *b, int x)
{
	int	i;
	int	rang_x;

	i = 1;
	if (x < b->data)
		rang_x = 1;
	while (x < b->data)
	{
		rang_x = i;
		b = b->next;
		i++;
	}
	return (i);
}

void	sort_b(t_stack *a, t_stack *b, int x)
{
	int	i;
	int	cpt;
	int	size;

	i = place_num(b, x);
	cpt = i;
	size = stack_size(b);
	if (i == 1)
		push_a(a, b);
	else if (i == 2)
	{
		push_a(a, b);
		swap_a(a);
	}
	else if (i == size + 1)
	{
		push_a(a, b);
		rotate_b(b);
	}
	else if (i >= 3 && i <= (size / 2))
	{
		while (i > 0)
		{
			rotate_b(b);
			i--;
		}
		push_a(a, b);
		i = cpt;
		while (i > 0)
		{
			rrotate_b(b);
			i--;
		}
	}
	else if (i >= 3 && i > (size / 2))
	{
		i = cpt;
		cpt = size - i;
		while (cpt > 0)
		{
			rrotate_b(b);
			cpt--;
		}
		cpt = size - i + 1;
		while (cpt > 0)
		{
			push_a(a, b);
			cpt--;
		}
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	while (stack_sorted(a) == 0)
	{
	   if(a->data < b->data)
		{
			if (a->data > last_int(a))
				rotate_a(a);
			if (a->data > a->next->data)
				swap_a(a);
		}
	   else
		   sort_b(a, b, a->data);
	}
	while (b->next)
	{
		push_a(b, a);
	}
}*/
