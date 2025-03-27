/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:38:30 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/27 18:05:55 by juanrome         ###   ########.fr       */
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

int select_pivot(t_node *stack)
{
    int size = stack_size(stack);
    int *array = malloc(size * sizeof(int));
    t_node *actual = stack;

    if (!array) {
        printf("Error: Fallo al asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        array[i] = actual->value;
        actual = actual->next;
    }

    qsort(array, size, sizeof(int), compare);

    int pivot = array[size / 2];
    free(array);

    return pivot;
}

void    split_stacks(t_node **stack_a, t_node **stack_b, int pivot, int *count) 
{
    t_node *temp = NULL;

    while (*stack_a)
    {
        if ((*stack_a)->value < pivot)
        {
            printf("Moviendo %d a stack_b\n", (*stack_a)->value);
            pb(stack_b, stack_a, count);
        }
        else
        {
            printf("Rotando %d en stack_a\n", (*stack_a)->value);
            ra(stack_a, count);
        }
        printf("Evaluando %d en stack_a\n", (*stack_a)->value);
if ((*stack_a)->value < pivot) {
    pb(stack_b, stack_a, count);
} else {
    ra(stack_a, count);
}
    }
    
}

void    merge_stacks(t_node **stack_a, t_node **stack_b, int *count)
{
    while (*stack_b) {
        pa(stack_a, stack_b, count);
    }
}

void    quicksort_stacks(t_node **stack_a, t_node **stack_b, int *count)
{
    int pivot;
    
    if (!(*stack_a) || !((*stack_a)->next))
        return;

    pivot = select_pivot(*stack_a);
    split_stacks(stack_a, stack_b, pivot, count);
    
    if (*stack_a && (*stack_a)->next)
        quicksort_stacks(stack_a, stack_b, count);
    if (*stack_b && (*stack_b)->next)
    quicksort_stacks(stack_b, stack_a, count);

    merge_stacks(stack_a, stack_b, count);
}
