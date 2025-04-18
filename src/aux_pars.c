/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/04/02 19:50:34 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isnumber(char **strs)
{
    const char *s;

    while (*strs != NULL)
    {
        s = *strs;
        if ((*s == '-' || *s == '+') && *(s + 1) == '\0')
            return 0;
        if (*s == '-' || *s == '+')
            s++;
        if (*s == '\0')
            return 0;
        while (*s != '\0')
        {
            if (!isdigit(*s))
                return 0;
            s++;
        }
        strs++;
    }
    return 1;
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

int aux_s(char **split, t_stacks *stacks, int *num, int *ln)
{
    long atoi;

    while (*split)
    {
        atoi = ft_atoi(*split);
        if (atoi > INT_MAX || atoi < INT_MIN) {
            printf("Error: Número fuera de rango.\n");
            return 0;
        }
        if (is_duplicate(num, *ln, (int)atoi)) {
            printf("Error: Duplicado.\n");
            return 0;
        }
        num[(*ln)++] = (int)atoi;
        push(&stacks->stack_a, (int)atoi);
        split++;
        printf("Contenido de stack_a: \n");
        t_node *actual = stacks->stack_a; 
        while (actual != NULL)
        {
            printf("nodo --> %d \n", actual->value);
            actual = actual->next;
        }
        printf("\n");
    }
    return 1;
}

