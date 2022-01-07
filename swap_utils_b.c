/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:08 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/07 14:08:50 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*swap_b(t_num *b)
{
	int		tmp;
	t_num	*cpy;
	t_num	*ret;

	cpy = b;
	ret = b;
	tmp = cpy->data;
	cpy->data = b->data;
	cpy = cpy->next;
	b->data = cpy->data;
	b = b->next;
	b->data = tmp;
	write (1, "sb\n", 3);
	return (ret);
}

t_stack	*push_a(t_num *a, t_num *b)
{
	int		cpy;
	t_stack	*stack;

	stack = malloc(sizeof(t_num *) * (stack_size(a) + stack_size(b)));
	stack->a = a;
	stack->b = b;
	cpy = stack->a->data;
	stack->a->data = stack->b->data;
	stack->b->data = cpy;
	write (1, "pa\n", 3);
	return (stack);
}

t_num	*rotate_b(t_num *b)
{
	int		tmp;
	t_num	*cpy;
	t_num	*ret;

	ret = b;
	cpy = b;
	tmp = b->data;
	cpy = cpy->next;
	while (b->next)
	{
		b->data = cpy->data;
		b = b->next;
		cpy = cpy->next;
	}
	b->data = tmp;
	write (1, "rb\n", 3);
	return (ret);
}

t_num	*rrotate_b(t_num *b)
{
	t_num	*head;
	t_num	*tmp;

	if (b->next)
	{
		head = b;
		while (b->next->next)
		{
			b = b->next;
			b->pos = b->pos + 1;
		}
		tmp = b->next;
		b->next = NULL;
		b = head;
		b->pos = b->pos + 1;
		tmp->next = b;
		b = tmp;
		b->pos = 1;
	}
	write (1, "rrb\n", 4);
	return (b);
}
