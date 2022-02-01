/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:30:26 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/01 17:09:31 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_free(char **tmp, int j)
{
	while (j >= 0)
		free(tmp[j--]);
	free (tmp);
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

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		i++;
		if (check_int(argv[i]) == 0 || check_doubles(argv, argv[i], i) == 0)
		{
			write (1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}
