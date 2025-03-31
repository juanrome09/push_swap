/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 05:46:35 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/31 21:36:01 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrb(t_node **stack_b, int *count)
{
    t_node *last;
    t_node *second_last;

    if (!*stack_b || !(*stack_b)->next)
        return;

    last = *stack_b;
    second_last = NULL;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;

    (*count)++;
}

void rrr(t_node **stack_a, t_node **stack_b, int *count)
{
    rra(stack_a, count);
    rrb(stack_b, count);
}

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value) {
            return 0; // No está ordenada.
        }
        stack = stack->next;
    }
    return 1; // Está ordenada.
}
