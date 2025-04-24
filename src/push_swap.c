/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:47 by alejagom          #+#    #+#             */
/*   Updated: 2025/04/24 17:33:53 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int counter_m = 0;

    if (argc < 2) {
        printf("Error: No se proporcionaron suficientes argumentos.\n");
        return 1;
    }

    t_stacks *stacks = init_stacks();
    if (!stacks) {
        printf("Error: No se pudo inicializar las pilas.\n");
        return 1;
    }

    if (!parseo(argv, stacks)) {
        free_stacks(stacks);
        printf("Error: No se pudieron analizar los argumentos.\n");
        return 1;
    }

    if (!stacks->stack_a) {
        printf("Error: stack_a está vacío después del análisis.\n");
        free_stacks(stacks);
        return 1;
    }

    int size = stack_size(stacks->stack_a);
    if (size <= 0) {
        printf("Error: Tamaño del stack inválido.\n");
        free_stacks(stacks);
        return 1;
    }

    if (size == 2)
        sort_two(&stacks->stack_a, &counter_m);
    else if (size == 3)
        sort_three(&stacks->stack_a, &counter_m);
    else if (size == 4)
        sort_four(&stacks->stack_a, &stacks->stack_b, &counter_m);
    else if (size == 5)
        sort_five(&stacks->stack_a, &stacks->stack_b, &counter_m);
    else if (size <= 7)
        sort_six_or_seven(&stacks->stack_a, &stacks->stack_b, &counter_m, size);
    else
        main_sort(stacks, &counter_m);  // 💡 Aquí va tu nueva función elegante

    // Debug opcional:
	//print_stack(stacks->stack_a, "stack_a");
    printf("Movimientos totales: %d\n", counter_m);

    free_stacks(stacks);
    return 0;
}
