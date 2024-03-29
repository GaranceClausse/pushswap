/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:15:35 by gclausse          #+#    #+#             */
/*   Updated: 2022/02/08 13:06:01 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi(const char *str)
{
	int			i;
	long int	nb;
	int			cpt;

	i = 0;
	nb = 0;
	cpt = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		cpt = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * cpt);
}
