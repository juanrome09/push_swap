/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 05:40:59 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/30 05:50:35 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_node **stack_b, int *count)
{
    t_node *temp;

    if (!*stack_b || !(*stack_b)->next)
        return;

    temp = (*stack_b)->next;
    (*stack_b)->next = temp->next;
    temp->next = *stack_b;
    *stack_b = temp;

    (*count)++;
}

void ss(t_node **stack_a, t_node **stack_b, int *count)
{
    sa(stack_a, count);
    sb(stack_b, count);
}

void rb(t_node **stack_b, int *count)
{
    t_node *temp;
    t_node *last;

    if (!*stack_b || !(*stack_b)->next)
        return;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;

    last = *stack_b;
    while (last->next)
        last = last->next;

    temp->next = NULL;
    last->next = temp;

    (*count)++;
}

void rr(t_node **stack_a, t_node **stack_b, int *count)
{
    ra(stack_a, count);
    rb(stack_b, count);
}
 
void rra(t_node **stack_a, int *count)
{
    t_node *last;
    t_node *second_last;

    if (!*stack_a || !(*stack_a)->next)
        return;

    last = *stack_a;
    second_last = NULL;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;

    (*count)++;
}
