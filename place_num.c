/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:27:15 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/25 19:38:34 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_a_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while( i < stack->start_b - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while( i < stack->size)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	stack_reverse_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while( i < stack->size)
	{
		if (stack->tab[i] < stack->tab[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}
		
/*		   printf("tab[0] = %d, tab[1] = %d, tab[2] = %d, tab[3] = %d, tab[4] = %d, tab[5] = %d, tab[6] = %d, tab[7] = %d\n", stack->tab[0], stack->tab[1],  stack->tab[2], stack->tab[3],  stack->tab[4], stack->tab[5],  stack->tab[6], stack->tab[7]);
}*/

int	get_small_val(t_stack *stack)
{
	int	i;
	int	val;

	i = 0;
	val = stack->tab[0];
	while (i < stack->start_b)
	{
		if (stack->tab[i] < val)
			val = stack->tab[i];
		i++;
	}
	return (val);
}

int	get_small_pos(t_stack *stack)
{
	int	i;
	int	val;
	int	pos;

	i = 0;
	pos = 0;
	val = get_small_val(stack);
	while(stack->tab[i] != val)
	{
		pos++;
		i++;
	}
	return (pos);
}

int	get_big_val(t_stack *stack)
{
	int	i;
	int	val;

	i = stack->start_b;
	val = stack->tab[i];
	while (i <= stack->size)
	{
		if (stack->tab[i] > val)
			val = stack->tab[i];
		i++;
	}
	return (val);
}

int	get_big_pos(t_stack *stack)
{
	int	i;
	int	val;
	int	pos;

	i = stack->start_b;
	pos = 0;
	val = get_big_val(stack);
//	if (stack->tab[i])
//	{
		while(stack->tab[i] != val)
		{
			pos++;
			i++;
		}
//	}
	return (pos);
}


void	push_swap_small(t_stack *stack)
{
	int	small_pos;
	int	small_val;
	int	i;


	i = 0;
	while (i <= stack->size - 3)
	{
		small_pos = get_small_pos(stack);
		small_val = get_small_val(stack);
		if (small_pos == 0)
			push_b(stack);
		else if (small_pos > (stack->start_b / 2))
		{
			while(small_val != stack->tab[0])
				rrotate_a(stack);
			push_b(stack);
		}
		else
		{
			while ( small_val != stack->tab[0])
				rotate_a(stack);
			push_b(stack);

		}
		i++;
	}
	sort_three(stack);
	while (i > 0)
	{
		push_a(stack);
		i--;
	}
}

void	push_swap_fifty(t_stack *stack)
{
	int	small_pos;
	int	small_val;
	int	i;


	i = 0;
	while (i < stack->size- 3)
	{
		small_pos = get_small_pos(stack);
		small_val = get_small_val(stack);
		printf("small pos= %d\n", small_pos);
		printf("small val= %d\n", small_val);
		printf ("stack->size / 4) = %d\n", stack->size / 4);

		if (small_pos == 0)
			push_b(stack);
		else if (small_pos > ((stack->size + 1) / 4))
		{
			while(small_val != stack->tab[0])
				rrotate_a(stack);
			push_b(stack);
		}
		else
		{
			while ( small_val != stack->tab[0])
				rotate_a(stack);
			push_b(stack);
		}
		i++;
	}
	sort_three(stack);
	while (i > 0)
	{
		push_a(stack);
		i--;
	}
}

void	push_swap_hundred(t_stack *stack)
{
	int	big_pos;
	int	big_val;
	int	i;
	int	len_b;


	i = stack->start_b;
	len_b = (stack->size + 1) / 2;
//	tmp = i;
	while (i <= stack->size)
	{
		big_pos = get_big_pos(stack);
		big_val = get_big_val(stack);
		printf("big pos= %d\n", big_pos);
		printf("big val= %d\n", big_val);
		printf("start_b = %d\n", stack->tab[stack->start_b]);
		printf("stack->start_b == %d\n", stack->start_b);
		printf("len_b = %d\n", (len_b / 2));
		if (big_pos <= len_b / 2)
		{
			while(big_val != stack->tab[stack->start_b])
			{
				rotate_b(stack);
			}
			push_a(stack);
			len_b--;
		}
		else
		{
			while (big_val != stack->tab[stack->start_b])
				rrotate_b(stack);
			push_a(stack);
			len_b--;
		}
		i++;
	}
	printf("b est vide\n");

	i = 0;
	while (i <= stack->size)
	{
		printf("tab[%d] = ", i);
		printf("%d\n", stack->tab[i]);
		i++;
	}	
	printf("on push ce qui est pas trie dan b\n");
	i = stack->size;
	while (i > stack->size / 2)
	{
		rrotate_a(stack);
		push_b(stack);
		//rrotate_a(stack);
		/*if (stack->tab[0] >= (get_median(stack) / 2 + 1))
		{
			printf ("get_median(stack) / 2 = %d\n", get_median(stack) / 2);
			push_b(stack);
		}
		if (stack->tab[0] > stack->tab[1] && stack->tab[stack->start_b] > stack->tab[stack->start_b + 1])
		{
			swap_a(stack);
			swap_b(stack);
		}
		if (stack->tab[stack->start_b] > stack->tab[stack->size])
		{
			rotate_b(stack);

		}*/	
		i--;
	}
	i = 0;
	while (i < stack->start_b)
	{
		printf("tab_a[%d] = ", i);
		printf("%d\n", stack->tab[i]);
		i++;
	}	
	printf("b est moitie rempli de la deuxieme moitie non tiree\n");

	i = stack->start_b;
	while (i <= stack->size)
	{
		printf("tab_b[%d] = ", i);
		printf("%d\n", stack->tab[i]);
		i++;
	}	
	printf("b est rempli de trucs non trie\n");

	i = stack->start_b;
//	printf("tab[start_b] = %d\n", stack->tab[stack->start_b]);
//	printf("start_b = %d\n", stack->start_b);
//	printf("stack size = %d\n", stack->size);
	while (i <= stack->size)
	{
		big_pos = get_big_pos(stack);
		big_val = get_big_val(stack);
		printf("i = %d\n", i);
		printf("big pos= %d\n", big_pos);
		printf("big val= %d\n", big_val);
		printf("start_b = %d\n", stack->start_b);
		printf("tab[start_b] = %d\n", stack->tab[stack->start_b]);
		//if (big_pos == 0)
		//	push_a(stack);
		if (big_pos > ((stack->size / 4)))
		{
			while(big_val != stack->tab[stack->start_b])
			{
				rrotate_b(stack);
				printf("tab[start_b] after irrb = %d\n", stack->tab[stack->start_b]);
				printf("i = %d\n", i);

			}
			push_a(stack);
		}
		else
		{
			while (big_val != stack->tab[stack->start_b])
			{
				rotate_b(stack);
				printf("tab[start_b] after rb = %d\n", stack->tab[stack->start_b]);
				printf("i = %d\n", i);
			}


			push_a(stack);
		}
		i++;
	}


}




void	sort_three(t_stack *stack)
{
	if (stack_a_sorted(stack) == 1)
		return ;
	if (stack->tab[0] > stack->tab[1])
	{
		if (stack->tab[1] > stack->tab[2] || (stack->tab[0] > stack->tab[1]
			&& stack->tab[0] > stack->tab[2]))
			rotate_a(stack);
		if (stack->tab[0] > stack->tab[1])
		       swap_a(stack);
	}
	else if (stack->tab[2] > stack->tab[0])
	{
		swap_a(stack);
 		rotate_a(stack);
	}
	else if (stack_a_sorted(stack) == 0)
		rrotate_a(stack);
}

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else 
			i++;
	}
	return (tab);
}

int	get_median(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	median;

	i = 0;
	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		median = tab[size / 2];
	else
		median = tab[size / 2 + 1];
	free(tab);
	return (median);
}

int	get_quartil(t_stack *stack)
{
	int	i;
	int	*tab;
	int	size;
	int	quartil;

	i = 0;
	size = stack->size + 1;
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = stack->tab[i];
		i++;
	}
	tab = sort_tab(tab, size);
	if (size % 2 == 0)
		quartil = tab[size / 4];
	else
		quartil = tab[size / 4 + 1];
	free(tab);
	return (quartil);
}


void	push_swap(t_stack *stack)
{
	int	median;
	int	i;

	i = 0;
	median = get_median(stack);
	printf("median= ??? %d\n",median);
	while (i <= stack->size)
	{
		if (stack->tab[0] >= median)
		{
			push_b(stack);
		
		}
		else
		{
			rotate_a(stack);
		}
		
		i++;
	}
	i = 0;
	while (i < stack->start_b)
	{
		printf("tab_a[%d] = ", i);
		printf("%d\n", stack->tab[i]);
		i++;
	}	
	printf("b est moitie rempli\n");

	i = stack->start_b;
	while (stack->tab[i])
	{
		printf("tab_b[%d] = ", i);
		printf("%d\n", stack->tab[i]);
		i++;
	}	
	printf("b est rempli de trucs non trie\n");

	push_swap_hundred(stack);
//	push_swap_fifty(stack);

}

