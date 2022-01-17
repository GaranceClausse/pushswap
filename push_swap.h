/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:06 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/17 18:49:07 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libc.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	size_b;
	int	*tab;
}	t_stack;


int		check_int(char *str);
int		check_doubles(char **argv, char *num, int pos);
t_stack	*create_a(int argc, char **argv);
t_stack	*init_b(int argc);

int		stack_sorted(t_stack *stack);
int		place_num(t_stack *b, int x);
void	sort_b(t_stack *a, t_stack *b, int x);
void	push_swap(t_stack *a, t_stack *b);

t_stack	*swap_a(t_stack *stack_a);
void	push_b(t_stack *a);
t_stack	*rotate_a(t_stack *stack_a);
t_stack	*rrotate_a(t_stack *stack_a);
/*
t_stack	*swap_b(t_stack *b);
t_stack	*push_a(t_stack *a);
t_stack	*rotate_b(t_stack *b);
t_stack	*rrotate_b(t_stack *b);i*/

#endif
