/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:47 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/21 17:51:23 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int		tmp;
	t_stack	*cpy;

	cpy = stack_a;
	tmp = cpy->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
	write (1, "sa\n", 3);
}

void	rotate_a(t_stack *stack_a)
{
	int	tmp;
	int	i;
		
	i = 0;
	tmp = stack_a->tab[0];
	while (stack_a->tab[i + 1])
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
	write (1, "ra\n", 3);
}

void	rrotate_a(t_stack *stack_a)
{
	int	i;
	int	tmp;

	i = stack_a->size;
	tmp = stack_a->tab[i];
	while (i > 0)
	{
		stack_a->tab[i]  = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = tmp;
}

void	push_b(t_stack *a)
{
	int	tmp;
	int	i;
		
	i = 0;
	tmp = a->tab[0];
	while (i <= a->size)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[a->size] = tmp;
	a->size -= 1;
	a->start_b -= 1;
}
