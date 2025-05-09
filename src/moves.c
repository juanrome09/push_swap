/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:12:28 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/09 19:02:35 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b, int *count)
{
	t_node	*temp;

	if (!(*stack_a))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	(*count)++;
	write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b, int *count)
{
	t_node	*temp;

	if (!(*stack_b))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	(*count)++;
	write(1, "pa\n", 3);
}

void	ra(t_node **stack_a, int *count)
{
	t_node	*temp;
	t_node	*current;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	current = *stack_a;
	while (current->next)
	{
		current = current->next;
	}
	current->next = temp;
	(*count)++;
	write(1, "ra\n", 3);
}

void	sa(t_node **stack_a, int *count)
{
	t_node	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	(*count)++;
	write(1, "sa\n", 3);
}
