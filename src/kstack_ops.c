/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kstack_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:38:30 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/09 19:59:55 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(t_stacks *stacks, int *count)
{
	int	len;

	len = stack_size(stacks->stack_a);
	assign_indices(stacks->stack_a);
	k_sort1(stacks, len, count);
	k_sort2(stacks, len, count);
}

void	assign_indices(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*compare;
	int		index;

	tmp = stack_a;
	while (tmp)
	{
		index = 0;
		compare = stack_a;
		while (compare)
		{
			if (compare->value < tmp->value)
			{
				index++;
			}
			compare = compare->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*actual;

	size = 0;
	actual = stack;
	while (actual)
	{
		size++;
		actual = actual->next;
	}
	return (size);
}

int	find_max_index(t_node *stack)
{
	int		max_index;
	t_node	*current;

	if (!stack)
		return (-1);
	max_index = stack->index;
	current = stack;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
		}
		current = current->next;
	}
	return (max_index);
}

int	find_position_by_index(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
		{
			return (pos);
		}
		stack = stack->next;
		pos++;
	}
	return (-1);
}
