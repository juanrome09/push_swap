/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:40 by alejagom          #+#    #+#             */
/*   Updated: 2025/04/08 17:46:23 by juanrome         ###   ########.fr       */
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

void		ra(t_node **stack, int *count);
void		rb(t_node **stack_b, int *count);
void		rrb(t_node **stack_b, int *count);
void		rr(t_node **stack_a, t_node **stack_b, int *count);
void		rra(t_node **stack_a, int *count);
void		rrr(t_node **stack_a, t_node **stack_b, int *count);
void		pa(t_node **stack_a, t_node **stack_b, int *count);
void		pb(t_node **stack_a, t_node **stack_b, int *count);
void		sa(t_node **stack_a, int *count);
void		sb(t_node **stack_b, int *count);
void		ss(t_node **stack_a, t_node **stack_b, int *count);
void		print_stack(t_node *stack, char *stack_name);
int			is_sorted(t_node *stack);

int			stack_size(t_node *stack);
int			compare(const void *a, const void *b);
void 		sort_two(t_node **stack, int *count);
void 		sort_three(t_node **stack, int *count);
void 		sort_four(t_node **stack_a, t_node **stack_b, int *count);
void 		sort_five(t_node **stack_a, t_node **stack_b, int *count);
void 		sort_six_or_seven(t_node **stack_a, t_node **stack_b, int *count, int size);
int 		find_min(t_node *stack);
int 		find_second_min(t_node *stack);

#endif
