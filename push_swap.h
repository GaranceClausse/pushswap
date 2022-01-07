/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:06 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/07 12:41:40 by gclausse         ###   ########.fr       */
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
	struct s_num	*begin;
	struct s_num	*next;
}	t_num;

typedef struct	s_stack
{
	t_num	*a;
	t_num	*b;
}	t_stack;

t_num	*ft_lstnew_int(int data, int pos);
int	check_int(char *str);
int	check_doubles(char **argv, char *num, int pos);
void ft_lstadd(t_num **alst, t_num *new);

t_num	*swap_a(t_num *stack_a);
t_num	*rotate_a(t_num *stack_a);
t_num	*rrotate_a(t_num *stack_a);


#endif
