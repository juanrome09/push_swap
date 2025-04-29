/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/04/29 18:58:04 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *s)
{
	if (!s || *s == '\0')
		return (0);
	if ((*s == '-' || *s == '+') && !isdigit(*(s + 1)))
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	isnumber(char **strs)
{
	int	i = 0;

	while (strs[i])
	{
		if (!is_valid_number(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int *num, int ln, int value)
{
	int	i;

	i = 0;
	while (i < ln)
	{
		if (num[i] == value)
			return (1);
		i++;
	}
	return (0);
}


int	aux_s(char **split, t_stacks *stacks, int **num, int *ln)
{
	long	n;
	int		*new_array;
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		n = ft_atoi_long(split[i]);
		if (n == 2147483648 || !is_valid_number(split[i]) || is_duplicate(*num, *ln, (int)n))
		{
			write(2, "Error\n", 6);
			return (0);
		}

		new_array = malloc(sizeof(int) * (*ln + 1));
		if (!new_array)
			return (0);

		j = 0;
		while (j < *ln)
		{
			new_array[j] = (*num)[j];
			j++;
		}
		new_array[*ln] = (int)n;
		free(*num);
		*num = new_array;

		if (!push_node(&stacks->stack_a, (int)n))
			return (0);

		(*ln)++;
		i++;
	}
	return (1);
}
