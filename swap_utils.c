/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:24:47 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/07 12:45:28 by gclausse         ###   ########.fr       */
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

int	last_int(t_num *lst)
{
	t_num	*last;

	last = lst;
	if (lst)
	{
		while (last->next)
		{
			last = last->next;
		}
	}
	return (last->data);
}


/*void	reverse_a(t_num *stack_a)
{
	int		tmp;
	t_num	*cpy;

	cpy = stack_a;
	tmp = stack_a->data;
	while (stack_a->next)
	{
		stack_a->data = cpy->data;
		cpy = cpy->next;
		stack_a = stack_a->next;
	}
	
}

t_num	*rrotate_a(t_num *stack_a)
{
	t_num	*cpy;
	int		tmp;

	cpy = stack_a;
	while (cpy->next)
		cpy = cpy->next;
	tmp = cpy->data;
	reverse_a(stack_a);
	cpy = stack_a;
	cpy->data = tmp;
	return (stack_a);
}*/

t_num		*rrotate_a(t_num *stack_a)
{
	t_num	*head;
	t_num	*tmp;

	if (stack_a->next)
	{
		head = stack_a;
		while (stack_a->next->next)
		{
			stack_a = stack_a->next;
			stack_a->pos = stack_a->pos + 1;
		}
		tmp = stack_a->next;
		stack_a->next = NULL;
		stack_a = head;
		stack_a->pos = stack_a->pos + 1;
		tmp->next = stack_a;
		stack_a = tmp;
		stack_a->pos = 1;
	}
	return (stack_a);
}



















