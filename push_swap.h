/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:06 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/24 12:06:21 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	start_b;
	int	*tab;
}	t_stack;


int		check_int(char *str);
int		check_doubles(char **argv, char *num, int pos);
t_stack	*create_a(int argc, char **argv, t_stack *stack);
t_stack	*init_b(int argc);

int		stack_sorted(t_stack *stack);
int		place_num(t_stack *b, int x);
void	sort_b(t_stack *stack, int x);
void	push_swap(t_stack *stack);

void	swap_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rrotate_a(t_stack *stack);

void	swap_b(t_stack *stack);
void	push_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rrotate_b(t_stack *stack);

void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);

#endif
