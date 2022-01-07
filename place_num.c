/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/07 13:47:11 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_num *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	if (stack->next == NULL)
		return (1);
	else
		return (0);
}

int	place_num(t_num *b, int x)
{
	int	i;
	int	rang_x;

	i = 1;
	if (x < b->data)
		rang_x = 1;
	while (x < b->data)
	{
		rang_x = i;
		b->next;
		i++;
	}
	return (i);
}

void	sort_b(t_num *b, int x)
{
	int	i;
	int	cpt;
	int	size;

	i = place_num(b, x);
	cpt = i;
	size = ft_lstsize(b);
	if (i = 1)
		pa;
	else if (i = 2)
	{
		pa;
		sa;
	}
	else if (i = size + 1)
	{
		pa;
		rotate_b(b);
	}
	else if (i >= 3 && i <= (size / 2))
	{
		while (i > 0)
		{
			rotate_b(b);
			i--;
		}
		pa;
		i = cpt;
		while (i > 0)
		{
			rrotate_b(b);
			i--;
		}
	}
	i = cpt;
	else if (i >= 3 && i > (size / 2))
	{
		cpt = size - i;
		while (cpt > 0)
		{
			rrotate_b(b);
			cpt--;
		}
		cpt = size - i + 1;
		while (cpt > 0)
		{
			pa;
			cpt--;
		}
	}
}

void	push_swap(t_num *a, t_num *b)
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
		   sort_b(b, a->data);
	}
	while (b->next)
	{
		push_b(a, b);
	}
}
