/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/26 18:13:25 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_afficher(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->size)
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}

t_stack	*create_a(int argc, char **argv, t_stack *stack)
{
	int		i;
	
	i = argc - 2;
	stack->tab = malloc(sizeof(int) * (argc));
	if (!stack->tab)
		return (NULL);
	stack->size = i;
	stack->start_b = i + 1;
	while (i >= 0)
	{
		stack->tab[i] = ft_atoi(argv[i + 1]);
		//printf("tab[i] = %d\n", stack->tab[i]);
		i--;
	}
	return (stack);
}

void	malloc_pbm(char **tmp, int j)
{
	while (j >= 0)
		free(tmp[j--]);
	free (tmp);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	t_stack	*stack;

	i = 0;
	j = 0;
	if (argc < 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[i])
		{
			argv[i + 1] = tmp[i];
			i++;
		}
		argc = i + 1;
		j = i - 1;
	}
	i = 0;
	while (i < argc - 1)
	{
			i++;
		if (check_int(argv[i]) == 0 || check_doubles(argv, argv[i], i) == 0)
		{
			write (1, "Error\n", 6);
			if (j > 0)
				malloc_pbm(tmp, j);
			return (0);
		}
	}
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack = create_a(argc, argv, stack);
	if (stack_a_sorted(stack))
			return (0);
	if (argc <= 4)
		sort_three(stack);
	else if (argc > 4 && argc < 99)
		push_swap_small(stack);
	else if (argc > 99 && argc < 500)
		push_swap_hundred_init(stack);
	else if (argc >= 500)
		push_swap_fivehundred_init(stack);
//	ft_afficher(stack);
	return (0);
}
