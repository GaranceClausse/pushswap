/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/04 15:40:52 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	place_num(size_t b, int x)
{
	int	i;
	int	rang_x;

	i = 1;
	if (x < b(i))
		rang_x = 1;
	while (x < b(i))
	{
		rang_x = i;
		i++;
	}
	return (i);
}

void	sort_b(size_t b, int x)
{
	int	i;
	int	size;

	i = place_num(b, x);
	size = ft_lstsize(b);
	if (i = 1)
		pa;
	else if (i = 2)
	{
		pa;
		sa;
	}
}
