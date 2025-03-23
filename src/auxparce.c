/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxparce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/03/23 20:52:58 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_number(const char *str)
{
	int	j;

	j = 0;
	if (str == NULL)
		return (0);
	if (str[j] == '-' || str[j] == '+')
	{
		j++;
	}
	if (str[j] == '\0')
	{
		return (0);
	}
	while (str[j] != '\0')
	{
		if (!isdigit(str[j]))
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	are_all_numbers(char **strs)
{
	while (*strs != NULL)
	{
		if (!single_number(*strs))
		{
			return (0);
		}
		strs++;
	}
	return (1);
}

int	isnumber(char **str)
{
	if (!are_all_numbers(str))
	{
		free_wd(str);
		return (0);
	}
	return (1);
}

int is_duplicate(int *array, int size, int num)
{
	int i;

	i = 0;
    while (i < size)
    {
        if (array[i] == num)
            return (1); // Devuelve 1 si hay un duplicado.
    }
	i++;
    return (0); // Devuelve 0 si no hay duplicados.
}

void    aux_s(char **split, t_stacks *stacks, int *num, int *ln)
{
    while (*split)
    {
        int atoi = ft_atoi(*split);
        if (is_duplicate(num, *ln, atoi))
        {
            printf("Error: El número %d está duplicado.\n", atoi);
            exit(1); // Termina ejecución en caso de error.
        }
        num[(*ln)++] = atoi;
        push(&stacks->stack_a, atoi);
        split++;
    }
}