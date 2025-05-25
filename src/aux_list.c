/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:36:41 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/24 21:09:36 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;	

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return (stacks);
}

int	push_node_end(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (1);
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	free_node(t_node **stack)
{
	t_node	*actual;
	t_node	*temp;

	actual = *stack;
	while (actual != NULL)
	{
		temp = actual;
		actual = actual->next;
		free(temp);
	}
	*stack = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	t_node	*current;
	t_node	*temp;

	if (!stacks)
		return ;
	current = stacks->stack_a;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	current = stacks->stack_b;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stacks);
}
