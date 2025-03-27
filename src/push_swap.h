/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:40 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/27 17:31:15 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;

	struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
	t_node	*stack_a; // Pila A
	t_node	*stack_b; // Pila B
}	t_stacks;

int			is_duplicate(int *num, int ln, int atoi);
int			aux_s(char **split, t_stacks *stacks, int *num, int *ln);
int			parseo(char **args, t_stacks *stacks);
int			isnumber(char **str);
int			single_number(const char *str);
int			are_all_numbers(char **strs);
void		free_wd(char **words);
void		push(t_node **stack, int value);
t_stacks	*init_stacks(void);
void		free_stacks(t_stacks *stacks);
void		free_node(t_node **stack);
void		quicksort(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack, int *count);
void		pa(t_node **stack_a, t_node **stack_b, int *count);
void		pb(t_node **stack_a, t_node **stack_b, int *count);
void		split_stacks(t_node **stack_a, t_node **stack_b, int pivot, int *count);
int			select_pivot(t_node *stack);
void		merge_stacks(t_node **stack_a, t_node **stack_b, int *count);
void    	quicksort_stacks(t_node **stack_a, t_node **stack_b, int *count);
int			stack_size(t_node *stack);
int			compare(const void *a, const void *b);

#endif
