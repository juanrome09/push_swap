/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by juanrome         #+#    #+#             */
/*   Updated: 2025/05/05 19:02:58 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_num(const char *s)
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
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!val_num(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(int *num, int ln, int value)
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
	int		i;
	long	n;

	i = 0;
	while (split[i])
	{
		n = ft_atoi_long(split[i]);
		if (n == 2147483648 || is_dup(*num, *ln, (int)n))
			return (0);
		if (!val_num(split[i]))
			return (0);
		if (!add_number(num, ln, (int)n))
			return (0);
		if (!push_node_end(&stacks->stack_a, (int)n))
			return (0);
		i++;
	}
	return (1);
}

int	add_number(int **num, int *ln, int n)
{
	int	*new;
	int	j;

	new = malloc(sizeof(int) * (*ln + 1));
	if (!new)
		return (0);
	j = 0;
	while (j < *ln)
	{
		new[j] = (*num)[j];
		j++;
	}
	new[*ln] = n;
	free(*num);
	*num = new;
	(*ln)++;
	return (1);
}
