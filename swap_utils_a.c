/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:47 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/14 14:05:40 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_a(t_stack *stack_a)
{
	int		tmp;
	t_stack	*cpy;

	cpy = stack_a;
	tmp = cpy->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
	write (1, "sa\n", 3);
	return (stack_a);
}

t_stack	*rotate_a(t_stack *stack_a)
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
	return (stack_a);
}

t_stack	*rrotate_a(t_stack *stack_a)
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
	return (stack_a);
}

void	push_b(t_stack *a, t_stack *b)
{
	int		i;
	
	i = b->size + 1;
	printf("i = %d\n", i);
	while (i > 0)
	{
		printf("ca rentre");
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	printf("ici k");
	b->tab[0] = a->tab[0];
	printf("b tab[0] = %d\n", b->tab[0]);
	b->size += 1;
	i = 0;
	while (i < a->size)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->size -= 1;
}


