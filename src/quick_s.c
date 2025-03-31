/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:38:30 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/31 21:54:59 by juanrome         ###   ########.fr       */
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

	if(size == 0)
	   return -1;

    if (!array)
	{
        printf("Error: Fallo al asignar memoria.\n");
		free(array);
        return 0;
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
	}
}

void    merge_stacks(t_node **stack_a, t_node **stack_b, int *count)
{
    while (*stack_b) {
        pa(stack_a, stack_b, count);
    }
}

void quicksort_stacks(t_node **stack_a, t_node **stack_b, int *count) {
    int size = stack_size(*stack_a);

   if (size <= 1) {
        return; // Pila ya está ordenada.
    } else if (size == 2) {
        if (!is_sorted(*stack_a)) {
            sort_two(stack_a, count);
        }
    } else if (size == 3) {
        if (!is_sorted(*stack_a)) {
            sort_three(stack_a, count);
        }
    } else if (size == 4) {
        sort_four(stack_a, stack_b, count);
    } else if (size == 5) {
        sort_five(stack_a, stack_b, count);
    } else if (size <= 7) {
        sort_six_or_seven(stack_a, stack_b, count, size);
    } else {
        int pivot = select_pivot(*stack_a);
        split_stacks(stack_a, stack_b, pivot, count);
        quicksort_stacks(stack_a, stack_b, count);
        quicksort_stacks(stack_b, stack_a, count);
        merge_stacks(stack_a, stack_b, count);
    }
}
