/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/04/24 17:58:58 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int is_duplicate(int *num, int ln, int atoi) {
    if (!num || ln <= 0) {
        return 0;
    }

    int i = 0;
    while (i < ln) {
        if (num[i] == atoi)
            return 1;
        i++;
    }
    return 0;
}

int aux_s(char **split, t_stacks *stacks, int **num, int *ln) {
    long atoi;

    while (*split) {

        atoi = ft_atoi(*split);
        if (atoi == 0 && **split != '0')
            return 0;
        if (atoi > INT_MAX || atoi < INT_MIN)
            return 0;

        if (is_duplicate(*num, *ln, (int)atoi))
            return 0;

        int *temp = realloc(*num, sizeof(int) * (*ln + 1));
        if (!temp)
            return 0;
        *num = temp;

        (*num)[(*ln)++] = (int)atoi;
        if (!push_node(&stacks->stack_a, (int)atoi))
            return 0;
		
        split++;
    }
    return 1;
}
