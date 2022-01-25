/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:08 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/25 19:23:10 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *stack)
{
	int		tmp;
	t_stack	*cpy;

	cpy = stack;
	tmp = cpy->tab[stack->start_b];
	stack->tab[stack->start_b] = stack->tab[stack->start_b + 1];
	stack->tab[stack->start_b + 1] = tmp;
	write (1, "sb\n", 3);
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;
		
	i = stack->start_b;
	tmp = stack->tab[stack->start_b];
	while (i < stack->size)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->size] = tmp;
	write (1, "rb\n", 3);
}

void	rrotate_b(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->size;
	tmp = stack->tab[i];
	while (i > stack->start_b)
	{
		stack->tab[i]  = stack->tab[i - 1];
		i--;
	}
	stack->tab[stack->start_b] = tmp;
	write(1, "rrb\n", 4);
}

void	push_a(t_stack *stack)
{
	int	tmp;
	int	i;
		
	i = stack->start_b;
	tmp = stack->tab[stack->start_b];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = tmp;
	stack->start_b += 1;
	write(1, "pa\n", 3);
}
