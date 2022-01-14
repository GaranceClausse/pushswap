/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/14 13:35:48 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_afficher(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->tab[i])
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}

t_stack	*create_a(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	
	i = argc - 2;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->tab = malloc(sizeof(int) * (argc));
	if (!stack_a->tab)
		return (NULL);
	stack_a->size = i;
	stack_a->tab[argc - 1] = '\0';
	while (i >= 0)
	{
		stack_a->tab[i] = ft_atoi(argv[i + 1]);
		printf("tab[i] = %d\n", stack_a->tab[i]);
		i--;
	}
	return (stack_a);
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
	while (i < pos)
	{
		if (ft_atoi(argv[i]) == ft_atoi(num))
			return (0);
		i++;
	}
	return (1);
}

void	malloc_pbm(char **tmp, int j)
{
	while (j > 0)
		free(tmp[j--]);
	free (tmp);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	t_stack	*a;
//	t_stack	*b;

	i = 0;
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
		j = i + 1;
	}
	i = 0;
	while (i < argc - 1)
	{
		i++;
		if (check_int(argv[i]) == 0 || check_doubles(argv, argv[i], i) == 0)
		{
			write (1, "Error\n", 6);
			malloc_pbm(tmp, j);
			return (0);
		}
	}
//	a = malloc(sizeof(t_stack *));
	a = (create_a(argc, argv));
	printf("a = \n");
	ft_afficher(a);
	printf("rrotate = \n");
	ft_afficher(rrotate_a(a));
	printf("rotate = \n");
	ft_afficher(rotate_a(a));
		//push_swap(create_a(argc, argv), b);
	return (0);
}
