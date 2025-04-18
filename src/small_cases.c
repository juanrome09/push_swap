/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:21 by juanrome          #+#    #+#             */
/*   Updated: 2025/04/10 12:57:36 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_node **stack, int *count)
{
    if ((*stack)->value > (*stack)->next->value)
	{
        sa(stack, count); 
    }
}

void sort_three(t_node **stack, int *count)
{
    int a = (*stack)->value;
    int b = (*stack)->next->value;
    int c = (*stack)->next->next->value;

    printf("Valores actuales: a = %d, b = %d, c = %d\n", a, b, c);

    if (a > b && b > c) // Caso completamente desordenado
    {
		printf("AQUI 1");
        sa(stack, count);  // Intercambia los primeros dos
        rra(stack, count); // Mueve el mayor al final
    }
    else if (a > c && c > b) // Caso a > c > b
    {
		printf("AQUI 2");
        ra(stack, count);  // Mueve el mayor al final
    }
    else if (b > a && a > c) // Caso b > a > c
    {
		printf("AQUI 3");
        rra(stack, count);  // Intercambia los primeros dos
    }
    else if (b > c && c > a) // Caso b > c > a
    {
		printf("AQUI 4");
        rra(stack, count); // Mueve el menor al inicio
        sa(stack, count);  // Intercambia los primeros dos
    }
     else if (a < b && b > c) // Caso a < b > c
    {
		printf("AQUI 5");
        ra(stack, count);  // Mueve el mayor al final
        sa(stack, count);  // Intercambia los primeros dos
	}
    else if (a > b && b < c)
	{  // Mueve el mayor al final
        sa(stack, count);  // Intercambia los primeros dos
    }
}



void sort_four(t_node **stack_a, t_node **stack_b, int *count) {
    int min = find_min(*stack_a);
	if (min == -1){
		printf("no se encontro el valor min");
		return;
		}

    while ((*stack_a)->value != min) {
        ra(stack_a, count);
    }
    pb(stack_a, stack_b, count);

    sort_three(stack_a, count);

    pa(stack_a, stack_b, count);
}

void sort_five(t_node **stack_a, t_node **stack_b, int *count)
{
    int min = find_min(*stack_a);
    int second_min = find_second_min(*stack_a);

    if (min == -1 || second_min == -1) // Validar que los mínimos sean válidos
    {
        printf("Error: No se pudo encontrar el mínimo o el segundo mínimo.\n");
        return;
    }

    // Mover el menor a stack_b
    while ((*stack_a)->value != min)
    {
        ra(stack_a, count); // Rotar hasta que el menor esté al inicio
    }
    pb(stack_a, stack_b, count); // Push del menor a stack_b

    // Mover el segundo menor a stack_b
    while ((*stack_a)->value != second_min)
    {
        ra(stack_a, count); // Rotar hasta que el segundo menor esté al inicio
    }
    pb(stack_a, stack_b, count); // Push del segundo menor a stack_b

    // Ordenar los tres elementos restantes
    sort_three(stack_a, count);

    // Regresar los dos menores desde stack_b a stack_a
    pa(stack_a, stack_b, count); // Push del segundo menor
    pa(stack_a, stack_b, count); // Push del menor
}

void sort_six_or_seven(t_node **stack_a, t_node **stack_b, int *count, int size) {
    int moves = size - 3; 

    for (int i = 0; i < moves; i++) {
        int min = find_min(*stack_a);
        while ((*stack_a)->value != min) {
            ra(stack_a, count);
        }
        pb(stack_a, stack_b, count);
    }

    if (size == 6) {
        sort_three(stack_a, count);
    } else {
        sort_three(stack_a, count);
    }

    while (*stack_b) {
        pa(stack_a, stack_b, count);
    }
}

int find_min(t_node *stack)
{
    if (!stack)
    {
        printf("Error: La pila está vacía.\n");
        return -1;
    }

    int min = stack->value;
    t_node *current = stack->next;

    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }

    return min;
}

int find_second_min(t_node *stack)
{
    if (!stack || !stack->next)
    {
        printf("Error: La pila no tiene suficientes elementos.\n");
        return -1;
    }

    int min = find_min(stack);
    if (min == -1)
        return -1;

    int second_min = INT_MAX;
    t_node *current = stack;

    while (current)
    {
        if (current->value > min && current->value < second_min)
            second_min = current->value;
        current = current->next;
    }

    return (second_min == INT_MAX) ? -1 : second_min;
}
