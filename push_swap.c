/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/04 17:23:29 by gclausse         ###   ########.fr       */
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

t_num	**create_a(int len, int data)
{
	t_num	**stack_a;
	int		i;

	i = 1;
	stack_a = malloc(size_of(t_num) * len);
	if (!stack_a)
		return (NULL);
	while (i <= len)
	{
		ft_lstadd_back(stack_a, ft_lstnew_int(data, i));
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
		if (str[i] == "-")
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
	while (argv[i])
	{
		if (check_int(argv[i]) == 0)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}

}
