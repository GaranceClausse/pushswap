/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:11:25 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/01 15:27:46 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	int	i;
	int	cpt;

	i = 1;
	cpt = 1;
	while (i < stack->start_b)
	{
		if (stack->tab[i] > stack->tab[i - 1])
		{
			i++;
			cpt++;
		}
		else
			i++;
	}
	if (cpt != i)
		return (0);
	return (1);
}
