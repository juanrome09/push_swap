/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:38:30 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/18 13:27:46 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int stack_size(t_node *stack)
{
    int size = 0;
    t_node *actual = stack;

    while (actual)
    {
        size++;
        actual = actual->next;
    }
    return size;
}

void print_stack(t_node *stack, char *stack_name)
{
    printf("Contenido de %s: ", stack_name);
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}
