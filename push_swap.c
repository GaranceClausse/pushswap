/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/24 11:22:38 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_afficher(t_stack *stack)
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
	printf("i = %d et size = %d\n", i , stack->size);
	stack->start_b = i + 1;
	while (i >= 0)
	{
		stack->tab[i] = ft_atoi(argv[i + 1]);
		//printf("tab[i] = %d\n", stack->tab[i]);
		i--;
	}
	return (stack);
}

int	check_int(char *str)
{
	int			i;
	long int	num;

	i = 0;
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
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
	while (i < pos - 1)
	{
		if (ft_atoi(argv[i]) == ft_atoi(num))
			return (0);
		i++;
	}
	return (1);
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
	ft_afficher(stack);
	if (argc == 4)
	{
		printf("arg = 4\n");
		sort_three(stack);
		ft_afficher(stack);
		return (0);
	}
	if (argc == 6)
	{
		printf("arg = 6\n");
		sort_five(stack);
		ft_afficher(stack);
		return (0);
	}

	push_swap(stack);
	ft_afficher(stack);
	return (0);
}
