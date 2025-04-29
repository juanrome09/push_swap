/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:40 by alejagom          #+#    #+#             */
/*   Updated: 2025/04/29 18:35:31 by juanrome         ###   ########.fr       */
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
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stacks
{
    t_node  *stack_a; // Pila A
    t_node  *stack_b; // Pila B
} t_stacks;

// Funciones de inicialización y liberación de pilas
t_node      *create_node(int value);
int         push_node(t_node **stack, int value);
t_stacks    *init_stacks(void);
void        free_stacks(t_stacks *stacks);
void        free_node(t_node **stack);

// Funciones de operaciones en las pilas
void        ra(t_node **stack, int *count);
void        rb(t_node **stack_b, int *count);
void        rrb(t_node **stack_b, int *count);
void        rr(t_node **stack_a, t_node **stack_b, int *count);
void        rra(t_node **stack_a, int *count);
void        rrr(t_node **stack_a, t_node **stack_b, int *count);
void        pa(t_node **stack_a, t_node **stack_b, int *count);
void        pb(t_node **stack_a, t_node **stack_b, int *count);
void        sa(t_node **stack_a, int *count);
void        sb(t_node **stack_b, int *count);
void        ss(t_node **stack_a, t_node **stack_b, int *count);

// Funciones de ordenación
void        sort_two(t_node **stack, int *count);
void        sort_three(t_node **stack, int *count);
void        sort_four(t_node **stack_a, t_node **stack_b, int *count);
void        sort_five(t_node **stack_a, t_node **stack_b, int *count);
void        sort_six_or_seven(t_node **stack_a, t_node **stack_b, int *count, int size);
void        k_sort2(t_stacks *stacks, int len, int *count);
void        k_sort1(t_stacks *stacks, int len, int *count);
void        main_sort(t_stacks *stacks, int *count);

// Funciones auxiliares
int         is_sorted(t_node *stack);
int         stack_size(t_node *stack);
int         find_min(t_node *stack);
int         find_second_min(t_node *stack);
int         find_max(t_node *stack);
int         find_max_index(t_node *stack);
int         find_position_by_index(t_node *stack, int index);
void        assign_indices(t_node *stack_a);
int         ft_sqrt(int nmb);
int         count_index(t_node *stack, int index);

// Funciones de validación y parseo
int         is_duplicate(int *num, int ln, int atoi);
int         aux_s(char **split, t_stacks *stacks, int **num, int *ln);
int         parseo(char **args, t_stacks *stacks);
int			is_valid_number(const char *s);
int         isnumber(char **str);
int         single_number(const char *str);
int         are_all_numbers(char **strs);
void        free_wd(char **words);


void print_stack(t_node *stack, char *stack_name);
#endif
