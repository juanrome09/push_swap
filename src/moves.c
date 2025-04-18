/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:12:28 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/04 17:59:21 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pb(t_node **stack_a, t_node **stack_b, int *count)
{
    if (!(*stack_a))
    return;

    t_node *temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
	(*count)++;
}

void pa(t_node **stack_a, t_node **stack_b, int *count)
{
    if (!(*stack_b))
    return;

    
    t_node *temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;
	(*count)++;
}

void ra(t_node **stack, int *count)
{
    if (!*stack || !(*stack)->next) // Si no hay al menos dos elementos
        return;

    t_node *temp = *stack;       // Primer nodo (temporal)
    t_node *current = *stack;

    while (current->next)        // Mover al último nodo de la pila
        current = current->next;

    *stack = temp->next;         // El segundo nodo se convierte en el primero
    temp->next = NULL;           // El primer nodo ahora apunta a NULL
    current->next = temp;        // El último nodo ahora apunta al primer nodo

    (*count)++;
}

void sa(t_node **stack_a, int *count)
{
    t_node *temp;

    if (!*stack_a || !(*stack_a)->next)
        return;

    temp = (*stack_a)->next;
    (*stack_a)->next = temp->next;
    temp->next = *stack_a;
    *stack_a = temp;

    (*count)++;
}


int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}
