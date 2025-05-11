/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:47 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/11 23:08:34 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			counter_m;
	t_stacks	*stacks;
	int			size;

	counter_m = 0;
	if (!init_stacks_parse(argc, argv, &stacks))
		return (1);
	if (is_sorted(stacks->stack_a))
	{
		free_stacks(stacks);
		return (0);
	}
	size = stack_size(stacks->stack_a);
	if (size == 2)
		sort_two(&stacks->stack_a, &counter_m);
	else if (size == 3)
		sort_three(&stacks->stack_a, &counter_m);
	else if (size == 5)
	{
		sort_fouven(&stacks->stack_a, &stacks->stack_b, &counter_m, size);
	}
	else
		main_sort(stacks, &counter_m);
	print_stack(stacks->stack_a);
	printf("Movimientos totales: %d\n", counter_m);
	free_stacks(stacks);
	return (0);
}

// Debug opcional:
void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
}
