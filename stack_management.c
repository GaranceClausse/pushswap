/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:41:01 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/07 13:48:25 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_size(t_num *lst)
{
	int		i;
	t_num	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
