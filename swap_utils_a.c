/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:47 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/31 17:56:09 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int		tmp;
	t_stack	*cpy;

	cpy = stack;
	tmp = cpy->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
	write (1, "sa\n", 3);
}

void	rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->tab[0];
	while (i < stack->start_b)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->tab[stack->start_b - 1] = tmp;
	write (1, "ra\n", 3);
}

void	rrotate_a(t_stack *stack)
{
	int	i;
	int	tmp;

	i = (stack->start_b) - 1;
	tmp = stack->tab[i];
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
	stack->tab[0] = tmp;
	write (1, "rra\n", 4);
}

void	push_b(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->tab[0];
	while (i < (stack->start_b))
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
	stack->start_b -= 1;
	stack->tab[stack->start_b] = tmp;
	write (1, "pb\n", 3);
}
