/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:36:41 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/07 15:22:43 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		printf("Error reservando memoria para init listas\n");
		exit(1);
	}
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return (stacks);
}

void	push(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		printf("Error reservando memoria para push listas");
		free(stack);
		exit(1);
	}
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
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

    // Liberar stack_a
    t_node *current = stacks->stack_a;
    while (current)
    {
        t_node *temp = current;
        current = current->next;
        free(temp); // Liberar cada nodo
    }

    // Liberar stack_b
    current = stacks->stack_b;
    while (current)
    {
        t_node *temp = current;
        current = current->next;
        free(temp); // Liberar cada nodo
    }

    free(stacks); // Liberar la estructura principal
}
