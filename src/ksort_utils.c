/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:48:53 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/09 20:00:42 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nmb)
{
	int	i;

	if (nmb < 0)
		return (-1);
	if (nmb < 4)
		return (1);
	i = 2;
	while (i * i < nmb)
		i++;
	if (i * i - nmb < nmb - (i - 1) * (i - 1))
		return (i);
	return (i - 1);
}

int	count_index(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	k_sort1(t_stacks *stacks, int len, int *count)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(len) * 14 / 10;
	while (stacks->stack_a)
	{
		if (stacks->stack_a->index <= i)
		{
			pb(&stacks->stack_a, &stacks->stack_b, count);
			i++;
		}
		else if (stacks->stack_a->index <= i + range)
		{
			pb(&stacks->stack_a, &stacks->stack_b, count);
			rb(&stacks->stack_b, count);
			i++;
		}
		else
			ra(&stacks->stack_a, count);
	}
}

void	k_sort2(t_stacks *stacks, int len, int *count)
{
	while (--len >= 0)
	{
		if (count_index(stacks->stack_b, len) <= stack_size(stacks->stack_b)
			/ 2)
		{
			while (stacks->stack_b->index != len)
				rb(&stacks->stack_b, count);
		}
		else
		{
			while (stacks->stack_b->index != len)
				rrb(&stacks->stack_b, count);
		}
		pa(&stacks->stack_a, &stacks->stack_b, count);
	}
}

int	init_stacks_parse(int argc, char **argv, t_stacks **stacks)
{
	if (argc < 2)
		return (0);
	*stacks = init_stacks();
	if (!*stacks || !parseo(argv, *stacks))
	{
		free_stacks(*stacks);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
