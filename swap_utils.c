/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:47 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/06 18:23:27 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*swap_a(t_num *stack_a)
{
	int		tmp;
	t_num	*cpy;
	t_num	*ret;

	cpy = stack_a;
	ret = stack_a;
	tmp = cpy->data;
	cpy->data = stack_a->data;
	cpy = cpy->next;
	stack_a->data = cpy->data;
	stack_a = stack_a->next;
	stack_a->data = tmp;
	return (ret);
}

t_stack	*push_a(t_stack *stack)
{
	int cpy;

	cpy = stack->a->data;
	stack->a->data = stack->b->data;
	stack->b->data = cpy;
	return (stack);

}

t_num	*rotate_a(t_num *stack_a)
{
	int		tmp;
	t_num	*cpy;
	t_num	*ret;

	ret = stack_a;
	cpy = stack_a;
	tmp = stack_a->data;
	cpy = cpy->next;
	while (stack_a->next)
	{
		stack_a->data = cpy->data;
		stack_a = stack_a->next;
		cpy = cpy->next;
	}
	stack_a->data = tmp;
	return (ret);
}

t_num	*rrotate_a(t_num *stack_a)
{

}
