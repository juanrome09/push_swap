/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:19:21 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/09 19:54:53 by juanrome         ###   ########.fr       */
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

void	sort_four(t_node **stack_a, t_node **stack_b, int *count)
{
	int	min;

	min = find_min(*stack_a);
	if (min == -1)
		return ;
	while ((*stack_a)->value != min)
	{
		ra(stack_a, count);
	}
	pb(stack_a, stack_b, count);
	sort_three(stack_a, count);
	pa(stack_a, stack_b, count);
}

void	sort_five(t_node **stack_a, t_node **stack_b, int *count)
{
	int	min;
	int	second_min;

	min = find_min(*stack_a);
	second_min = find_second_min(*stack_a);
	if (min == -1 || second_min == -1)
		return ;
	while ((*stack_a)->value != min)
	{
		ra(stack_a, count);
	}
	pb(stack_a, stack_b, count);
	while ((*stack_a)->value != second_min)
	{
		ra(stack_a, count);
	}
	pb(stack_a, stack_b, count);
	sort_three(stack_a, count);
	pa(stack_a, stack_b, count);
	pa(stack_a, stack_b, count);
}
