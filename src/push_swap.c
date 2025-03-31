/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:47 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/31 21:38:56 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int counter_m = 0;
    t_stacks *stacks;

    if (argc < 2) {
        printf("Error: No se proporcionaron suficientes argumentos.\n");
        return 1;
    }

    stacks = init_stacks();
    if (!stacks) {
        printf("Error: No se pudo inicializar las pilas.\n");
        return 1;
    }

    if (!parseo(argv, stacks)) {
        free_stacks(stacks);
        printf("Error: No se pudieron analizar los argumentos.\n");
        return 1;
    }

    printf("Todos los argumentos se analizaron correctamente.\n");

    quicksort_stacks(&stacks->stack_a, &stacks->stack_b, &counter_m);

    t_node *actual = stacks->stack_a;
    printf("Lista ordenada: ");
    while (actual) {
        printf("%d ", actual->value);
        actual = actual->next;
    }
    printf("\n");

    printf("Movimientos totales: %d\n", counter_m);

    free_stacks(stacks);
    return 0;
}
