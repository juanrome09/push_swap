/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:12:28 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/27 18:10:26 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_node **stack_a, t_node **stack_b, int *count)
{
    if (!(*stack_a))
    return;

    (*count)++;
    t_node *temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
}

void pa(t_node **stack_a, t_node **stack_b, int *count)
{
    if (!(*stack_b))
    return;

    (*count)++;
    t_node *temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;
}

void ra(t_node **stack, int *count) 
{
    if (!(*stack) || !((*stack)->next))
    return;

    (*count)++;
    t_node *temp = *stack;
    *stack = (*stack)->next;

    t_node *actual = *stack;
    while (actual->next) {
        actual = actual->next;
    }
    actual->next = temp;
    temp->next = NULL;
}

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}
