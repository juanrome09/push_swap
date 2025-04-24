/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:21 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/24 17:50:52 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -------- FUNCIONES DE ORDENAMIENTO PEQUEÑOS --------

void sort_two(t_node **stack, int *count) {
    if ((*stack)->value > (*stack)->next->value) {
        sa(stack, count);
    }
}

void sort_three(t_node **stack, int *count) {
    int a = (*stack)->value;
    int b = (*stack)->next->value;
    int c = (*stack)->next->next->value;

    if (a > b && b > c) {
        sa(stack, count);
        rra(stack, count);
    } else if (a > c && c > b) {
        ra(stack, count);
    } else if (b > a && a > c) {
        rra(stack, count);
    } else if (b > c && c > a) {
        rra(stack, count);
        sa(stack, count);
    } else if (a < b && b > c) {
        ra(stack, count);
        sa(stack, count);
    } else if (a > b && b < c) {
        sa(stack, count);
    }
}

void sort_four(t_node **stack_a, t_node **stack_b, int *count) {
    int min = find_min(*stack_a);

    if (min == -1) return;

    while ((*stack_a)->value != min) {
        ra(stack_a, count);
    }
    pb(stack_a, stack_b, count);
    sort_three(stack_a, count);
    pa(stack_a, stack_b, count);
}

void sort_five(t_node **stack_a, t_node **stack_b, int *count) {
    int min = find_min(*stack_a);
    int second_min = find_second_min(*stack_a);

    if (min == -1 || second_min == -1) return;

    while ((*stack_a)->value != min) {
        ra(stack_a, count);
    }
    pb(stack_a, stack_b, count);

    while ((*stack_a)->value != second_min) {
        ra(stack_a, count);
    }
    pb(stack_a, stack_b, count);

    sort_three(stack_a, count);

    pa(stack_a, stack_b, count);
    pa(stack_a, stack_b, count);
}

void sort_six_or_seven(t_node **stack_a, t_node **stack_b, int *count, int size) {
    int moves = size - 3;

    for (int i = 0; i < moves; i++) {
        int min = find_min(*stack_a);
        while ((*stack_a)->value != min) {
            ra(stack_a, count);
        }
        pb(stack_a, stack_b, count);
    }

    sort_three(stack_a, count);

    while (*stack_b) {
        pa(stack_a, stack_b, count);
    }
}

