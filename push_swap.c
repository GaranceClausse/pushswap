/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/06 20:15:35 by gclausse         ###   ########.fr       */
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

static void    ft_afficher(t_num *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->data);
        printf("%d\n\n", stack->pos);
        stack = stack->next;
    }
}

t_num	*create_a(int argc, char **argv)
{
	int	i;
	t_num	*stack_a;
	t_num	*tmp;

	i = argc - 1;
	stack_a = malloc(sizeof(t_num) * argc);
	if (!stack_a)
		return (NULL);
	stack_a = NULL;
	tmp = NULL;
	while (i >= 0)
	{
		stack_a = tmp;
		tmp = ft_lstnew_int(ft_atoi(argv[i]), i);
		tmp->next = stack_a;
		i--;
	}
	return (stack_a);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!((ft_isdigit(str[i]) == 1) || (str[i] >= 9 && str[i] <= 13)
		|| str[i] == ' '))
			return (0);
		i++;
	}

	return (1);
}

int	check_doubles(char **argv, char *num, int pos)
{
	int	i;

	i = 1;
	while (i < pos)
	{
		if (ft_atoi(argv[i]) == ft_atoi(num))
			return (0);
		i++;
	}
	return (1);
}

void malloc_pbm(char **tmp, int j)
{
	while (j > 0)
		free(tmp[j--]);
	free (tmp);
}

int	main(int argc, char **argv)
{
	int		i;
	int	j;
	char	**tmp;

	i = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[i])
		{

			argv[i + 1] = tmp[i];
			i++;
		}
		argc = i + 1;
		j = i + 1;
	}
	i = 1;
	while (i < argc)
	{
		if (check_int(argv[i]) == 0 || check_doubles(argv, argv[i], i) == 0)
		{
			write (1, "Error\n", 6);
			malloc_pbm(tmp, j);
			return (0);
		}
		i++;
	}
	
	ft_afficher(create_a(argc, argv));
	ft_afficher(rotate_a(create_a(argc, argv)));
	return (0);
}
