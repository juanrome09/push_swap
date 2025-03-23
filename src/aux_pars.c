/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/03/24 00:53:27 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isnumber(char **strs)
{
	const char *s;
	
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


int	is_duplicate(int *array, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	aux_s(char **split, t_stacks *stacks, int *num, int *ln)
{
	int	atoi;

	while (*split)
	{
		atoi = ft_atoi(*split);
		if (is_duplicate(num, *ln, atoi))
		{
			printf("Error: El número %d está duplicado.\n", atoi);
			exit(1);
		}
		num[(*ln)++] = atoi;
		push(&stacks->stack_a, atoi);
		split++;
	}
}
