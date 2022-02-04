/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/04 13:14:12 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	i = argc - 2;
	stack->tab = malloc(sizeof(int) * (argc));
	if (!stack->tab)
	{
		free (stack);
		return (NULL);
	}
	stack->size = i;
	stack->start_b = i + 1;
	while (i >= 0)
	{
		stack->tab[i] = ft_atoi(argv[i + 1]);
		i--;
	}
	return (stack);
}

void	choose_algo(int argc, t_stack *stack, char **tmp, int j)
{
	if (argc <= 4)
		sort_three(stack);
	else if (argc > 4 && argc < 60)
		push_swap_small(stack);
	else if (argc >= 60 && argc < 250)
		push_swap_hundred(stack);
	else if (argc >= 250)
		push_swap_fivehundred(stack);
	free(stack->tab);
	free(stack);
	if (j > 0)
		malloc_free(tmp, j);
}

void	split_args(int *argc, char ***argv, char ***tmp, int *j)
{
	int	i;

	i = 0;
	if ((*argv)[1][0] == '\0' || ft_strchr((*argv)[1], ' ') == 0)
		return ;
	*tmp = ft_split((*argv)[1], ' ');
	if (!(*tmp))
		return ;
	while ((*tmp)[i])
	{
		(*argv)[i + 1] = (*tmp)[i];
		i++;
	}
	*argc = i + 1;
	*j = i - 1;
}

int	main(int argc, char **argv)
{
	int		j;
	char	**tmp;
	t_stack	*stack;

	j = 0;
	tmp = NULL;
	if (argc < 2)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		split_args(&argc, &argv, &tmp, &j);
	stack = create_a(argc, argv);
	if (stack_sorted(stack) || (check_input(argc, argv) == 0))
	{
		if (j != 0)
			malloc_free(tmp, j);
		free(stack->tab);
		free(stack);
		return (0);
	}
	choose_algo(argc, stack, tmp, j);
	return (0);
}
