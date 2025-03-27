/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:21 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/27 18:29:33 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_node **stack, int *count) {
    if ((*stack)->value > (*stack)->next->value) {
        ra(stack, count); 
    }
}

void sort_three(t_node **stack, int *count) {
    int a = (*stack)->value;
    int b = (*stack)->next->value;
    int c = (*stack)->next->next->value;

    if (a > b && b > c) { 
        ra(stack, count); pb(stack, NULL, count); ra(stack, count); pb(NULL, stack, count);
    } else if (a > c && c > b) { 
}
}

void sort_four(t_node **stack_a, t_node **stack_b, int *count) {
    int min = find_min(*stack_a);

    while ((*stack_a)->value != min) {
        ra(stack_a, count);
    }
    pb(stack_a, stack_b, count);

    sort_three(stack_a, count);

    pa(stack_a, stack_b, count);
}

void sort_five(t_node **stack_a, t_node **stack_b, int *count)
{
    int min = find_min(*stack_a);
    int second_min = find_second_min(*stack_a);

    while ((*stack_a)->value != min && (*stack_a)->value != second_min) {
        ra(stack_a, count);
    }
    pb(stack_a, stack_b, count);

    while ((*stack_a)->value != second_min) {
        ra(stack_a, count);
    pb(stack_a, stack_b, count);

    sort_three(stack_a, count);

    pa(stack_a, stack_b, count);
    pa(stack_a, stack_b, count);
}
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

    if (size == 6) {
        sort_four(stack_a, stack_b, count);
    } else {
        sort_five(stack_a, stack_b, count);
    }

    while (*stack_b) {
        pa(stack_a, stack_b, count);
    }
}

int find_min(t_node *stack) {
    if (!stack) {
        printf("Error: La pila está vacía.\n");
        return -1;
    }

    int min = stack->value;
    t_node *current = stack;

    while (current) {
        if (current->value < min) {
            min = current->value;
        }
        current = current->next;
    }

    return min;
}

int find_second_min(t_node *stack)
{
    if (!stack || !stack->next) {
        printf("Error: La pila no tiene suficientes elementos.\n");
        return -1;
    }

    int min = find_min(stack);
    int second_min = INT_MAX;
    t_node *current = stack;

    while (current) {
        
        if (current->value > min && current->value < second_min) {
            second_min = current->value;
        }
        current = current->next;
    }

    if (second_min == INT_MAX) {
        printf("Error: No se encontró un segundo mínimo.\n");
        return -1;
    }

    return second_min;
}