/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:36:41 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/24 18:01:03 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

t_stacks *init_stacks(void)
{
    t_stacks *stacks;

    stacks = malloc(sizeof(t_stacks));
    if (!stacks)
        return NULL;
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
    return (stacks);
}

t_node *create_node(int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int push_node(t_node **stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return 0;

    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;

    return 1;
}

void free_node(t_node **stack)
{
    t_node *actual = *stack;
    while (actual != NULL)
    {
        t_node *temp = actual;
        actual = actual->next;
        free(temp);
    }
    *stack = NULL;
}

void free_stacks(t_stacks *stacks)
{
    if (!stacks)
        return;

    t_node *current = stacks->stack_a;
    while (current)
    {
        t_node *temp = current;
        current = current->next;
        free(temp);
    }

    current = stacks->stack_b;
    while (current)
    {
        t_node *temp = current;
        current = current->next;
        free(temp);
    }

    free(stacks);
}
