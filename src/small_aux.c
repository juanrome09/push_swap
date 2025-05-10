/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:51:33 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/09 20:06:09 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack)
{
	int		min;
	t_node	*current;

	if (!stack)
		return (-1);
	min = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_second_min(t_node *stack)
{
	int		min;
	int		second_min;
	t_node	*current;

	if (!stack || !stack->next)
		return (-1);
	min = find_min(stack);
	if (min == -1)
		return (-1);
	second_min = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->value > min && current->value < second_min)
			second_min = current->value;
		current = current->next;
	}
	if (second_min == INT_MAX)
		return (-1);
	return (second_min);
}

int	find_max(t_node *stack)
{
	t_node	*current;
	int		max;

	if (!stack)
		return (-1);
	current = stack->next;
	max = stack->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}
