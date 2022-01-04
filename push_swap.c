/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/04 18:49:56 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ft_lstnew_int(int data, int pos)
{
	t_num	*new_elem;

	new_elem = malloc(sizeof(t_num));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->pos = pos;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_lstadd(t_num **alst, t_num *new)
{
	t_num	*last;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			while ((*alst)->next)
			{
				*alst = (*alst)->next;
			}
			last = *alst;
			last->next = new;
		}
	}
}

t_num	**create_a(int len, int data)
{
	t_num	**stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i <= len)
	{
		ft_lstadd(stack_a, ft_lstnew_int(data, i));
		i++;
	}
	return (stack_a);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!((ft_isdigit(str[i]) == 1) || (str[i] >= 9 && str[i] <= 13)
		|| str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_int(argv[i]) == 0)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		printf("argv[i] = %d", ft_atoi(argv[i]));
		create_a(argc, ft_atoi(argv[i]));
		i++;
	}
	return (0);
}
