/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:36:41 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/22 22:08:47 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		printf("No se asigno memoria para las pilas\n");
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
		printf("Error");
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}
