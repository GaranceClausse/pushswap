/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:06 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/06 13:25:40 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libc.h>
# include "libft/libft.h"

typedef struct	s_num
{
	int				data;
	int				pos;
	struct s_num	*next;
}	t_num;

t_num	*ft_lstnew_int(int data, int pos);
int	check_int(char *str);
void ft_lstadd(t_num **alst, t_num *new);


#endif
