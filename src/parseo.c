/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by alejagom          #+#    #+#             */
/*   Updated: 2025/04/29 18:56:33 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_wd(char **words)
{
    int i = 0;

    if (words == NULL)
        return ;
    while (words[i])
    {
        free(words[i]);
        i++;
    }
    free(words);
}

int check_split(char **split_result, int *numbers)
{
    if (!split_result || !isnumber(split_result))
    {
        free_wd(split_result);
        return (0);
    }
    return (1);
}

int	parseo(char **args, t_stacks *stacks)
{
	int		i = 1;
	int		ln = 0;
	int		*num = NULL;
	char	**spl_re;

	while (args[i])
	{
		spl_re = ft_split(args[i], ' ');
		if (!spl_re || !isnumber(spl_re))
		{
			free_wd(spl_re);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (!aux_s(spl_re, stacks, &num, &ln))
		{
			free(num);
			free_stacks(stacks);
			free_wd(spl_re);
			exit(EXIT_FAILURE);
		}
		free_wd(spl_re);
		i++;
	}
	free(num);
	return (1);
}

