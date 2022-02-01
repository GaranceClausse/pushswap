/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:13:52 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/01 11:38:38 by gclausse         ###   ########.fr       */
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

int	*get_tab(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;

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
	median = tab[size / 2];
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
	quartil = tab[(size / 4) * 3];
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
	quartil = tab[size / 4 + 4];
	free(tab);
	return (quartil);
}

int	get_tenth(t_stack *stack)
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
	quartil = tab[size / 10];
	free(tab);
	return (quartil);
}

int	get_tentyth(t_stack *stack)
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
	quartil = tab[(size / 10) * 2];
	free(tab);
	return (quartil);
}

int	get_thirtyth(t_stack *stack)
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
	quartil = tab[(size / 10) * 3];
	free(tab);
	return (quartil);
}

int	get_fourtyth(t_stack *stack)
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
	quartil = tab[(size / 10) * 4];
	free(tab);
	return (quartil);
}

int	get_sixtyth(t_stack *stack)
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
	quartil = tab[(size / 10) * 6];
	free(tab);
	return (quartil);
}

int	get_eightyth(t_stack *stack)
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
	quartil = tab[(size / 10) * 8];
	free(tab);
	return (quartil);
}
