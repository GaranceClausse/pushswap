/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:08 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/21 15:40:49 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_b(t_stack *stack)
{
	int		tmp;
	t_stack	*cpy;

	cpy = stack;
	tmp = cpy->tab[stack->start_b];
	stack->tab[stack->start_b] = stack->tab[stack->start_b + 1];
	stack->tab[stack->start_b + 1] = tmp;
	write (1, "sb\n", 3);
	return (stack);
}

t_stack	*rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;
		
	i = stack->start_b;
	tmp = stack->tab[stack->start_b];
	while (stack->tab[i + 1])
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[i] = tmp;
	write (1, "rb\n", 3);
	return (stack);
}

t_stack	*rrotate_b(t_stack *stack)
{
	int	i;
	int	tmp;

	i = stack->size + stack->start_b;
	tmp = stack->tab[i];
	while (i > stack->start_b)
	{
		stack->tab[i]  = stack->tab[i - 1];
		i--;
	}
	stack->tab[stack->start_b] = tmp;
	return (stack);
}

void	push_a(t_stack *stack)
{
	int	tmp;
	int	i;
		
	i = 0;
	tmp = stack->tab[stack->start_b];
	while (i <= stack->start_b)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[0] = tmp;
	stack->size += 1;
	stack->start_b += 1;
}
