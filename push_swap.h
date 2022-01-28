/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:29:06 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/28 16:50:15 by gclausse         ###   ########.fr       */
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

void	ft_afficher(t_stack *stack);

int		check_int(char *str);
int		check_doubles(char **argv, char *num, int pos);
t_stack	*create_a(int argc, char **argv, t_stack *stack);
t_stack	*init_b(int argc);

int		stack_a_sorted(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		check_a(t_stack *stack, int begin, int stop);
int		stack_reverse_sorted(t_stack *stack);

int		get_small_pos(t_stack *stack);
int		get_small_val(t_stack *stack);
int		get_big_val(t_stack *stack);
int		get_big_pos(t_stack *stack);

void	push_and_rotate_median(t_stack *stack);
void	push_and_rotate_bigquartil(t_stack *stack);
void	push_and_rotate_quartil(t_stack *stack);
void	push_and_rotate_bigquartil_eighth(t_stack *stack);
void	sort_b(t_stack *stack);

void	sort_three(t_stack *stack);

void	push_swap_fivehundred_init(t_stack *stack);

void	push_swap_small(t_stack *stack);
void	push_swap_hundred(t_stack *stack);
void	push_swap_fivehundred(t_stack *stack);


int		*sort_tab(int *tab, int size);
int		get_biggest(t_stack *stack);
int		get_median(t_stack *stack);
int		get_bigquartil(t_stack *stack);
int		get_quartil(t_stack *stack);
int		get_eighth(t_stack *stack);
int		get_smalleighth(t_stack *stack);

void	swap_a(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rrotate_a(t_stack *stack);
void	push_b(t_stack *stack);

void	swap_b(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rrotate_b(t_stack *stack);
void	push_a(t_stack *stack);

#endif
