/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:13:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/28 16:49:28 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int	get_biggest(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	biggest;

	i = 0;
	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	biggest = tab[size - 1];
	free (tab);
	return (biggest);

}

int	get_median(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	median;

	i = 0;
	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		median = tab[size / 2];
	else
		median = tab[size / 2 + 1];
	free(tab);

	return (median);
}

int	get_bigquartil(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	quartil;

	i = 0;
	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		quartil = tab[(size / 4) * 3];
	else
		quartil = tab[(size / 4 + 1) * 3];
	free(tab);
	return (quartil);
}

int	get_eighth(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	eighth;

	i = 0;

	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		eighth = tab[(size / 8) * 7];
	else
		eighth = tab[(size / 8 + 1) * 7];
	free(tab);
	return (eighth);
}

int	get_smalleighth(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	eighth;

	i = 0;

	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		eighth = tab[(size / 8)];
	else
		eighth = tab[(size / 8 + 1)];
	free(tab);
	return (eighth);
}


int	get_quartil(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	quartil;

	i = 0;

	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		quartil = tab[size / 4];
	else
		quartil = tab[size / 4 + 1];
	free(tab);

	return (quartil);
}

