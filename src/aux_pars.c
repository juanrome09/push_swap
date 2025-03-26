/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/03/26 15:37:30 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(char **strs)
{
	const char	*s;

	while (*strs != NULL)
	{
		s = *strs;
		if (*s == '-' || *s == '+')
			s++;
		if (*s == '\0')
			return (0);
		while (*s != '\0')
		{
			if (!isdigit(*s))
				return (0);
			s++;
		}
		strs++;
	}
	return (1);
}

int	is_duplicate(int *num, int ln, int atoi)
{
	int	i;

	i = 0;
	while (i < ln)
	{
		if (num[i] == atoi)
			return (1);
		i++;
	}
	return (0);
}

void	aux_s(char **split, t_stacks *stacks, int *num, int *ln)
{
	long	atoi;

	while (*split)
	{
		atoi = ft_atoi(*split);
		if (is_duplicate(num, *ln, (int)atoi))
		{
			printf("Error: El número %ld está duplicado.\n", atoi);
			exit(1);
		}
		num[(*ln)++] = (int)atoi;
		push(&stacks->stack_a, (int)atoi);
		split++;
	}
}
