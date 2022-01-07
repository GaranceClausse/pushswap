/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:06 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/07 13:56:05 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libc.h>
# include "libft/libft.h"

typedef struct s_num
{
	int				data;
	int				pos;
	struct s_num	*next;
}	t_num;

typedef struct s_stack
{
	t_num	*a;
	t_num	*b;
}	t_stack;

t_num	*ft_lstnew_int(int data, int pos);
int		check_int(char *str);
int		check_doubles(char **argv, char *num, int pos);
void	ft_lstadd(t_num **alst, t_num *new);
int		last_int(t_num *lst);
int		stack_size(t_num *lst);

t_num	*swap_a(t_num *stack_a);
t_stack	*push_a(t_num *a, t_num *b);
t_num	*rotate_a(t_num *stack_a);
t_num	*rrotate_a(t_num *stack_a);

#endif
