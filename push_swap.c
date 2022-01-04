/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:52:20 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/04 15:40:01 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
