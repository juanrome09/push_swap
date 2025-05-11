/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:21 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/11 23:14:05 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -------- FUNCIONES DE ORDENAMIENTO PEQUEÑOS --------

void	sort_two(t_node **stack, int *count)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		sa(stack, count);
	}
}

void	sort_three(t_node **stack, int *count)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a < b && b > c && a < c)
	{
		sa(stack, count);
		ra(stack, count);
	}
	if (a > b && b < c && a < c)
		sa(stack, count);
	if (a < b && b > c && a > c)
		rra(stack, count);
	if (a > b && b < c && a > c)
		ra(stack, count);
	if (a > b && b > c)
	{
		sa(stack, count);
		rra(stack, count);
	}
}

void	sort_fouven(t_node **stack_a, t_node **stack_b, int *count, int len)
{
	int	min_value;
	int	remaining;

	remaining = len - 3;
	while (remaining--)
	{
		min_value = find_min(*stack_a);
		if (min_value == -1)
			return ;
		while ((*stack_a)->value != min_value)
		{
			if (get_index_distance(*stack_a, min_value) <= len / 2)
				ra(stack_a, count);
			else
				rra(stack_a, count);
		}
		pb(stack_a, stack_b, count);
	}
	sort_three(stack_a, count);
	while (*stack_b)
		pa(stack_a, stack_b, count);
}

int	get_index_distance(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
