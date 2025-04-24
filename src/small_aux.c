/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:51:33 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/24 17:51:44 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// -------- FUNCIONES AUXILIARES --------

int find_min(t_node *stack) {
    if (!stack) return -1;

    int min = stack->value;
    t_node *current = stack->next;

    while (current) {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }

    return min;
}

int find_second_min(t_node *stack) {
    if (!stack || !stack->next) return -1;

    int min = find_min(stack);
    if (min == -1) return -1;

    int second_min = INT_MAX;
    t_node *current = stack;

    while (current) {
        if (current->value > min && current->value < second_min)
            second_min = current->value;
        current = current->next;
    }

    return (second_min == INT_MAX) ? -1 : second_min;
}

int find_max(t_node *stack) {
    if (!stack) return -1;

    int max = stack->value;
    t_node *current = stack->next;

    while (current) {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }

    return max;
}