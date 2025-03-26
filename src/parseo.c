/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/26 15:35:24 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_wd(char **words)
{
	int	i;

	i = 0;
	if (words == NULL)
		return ;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	check_split(char **split_result, int *numbers)
{
	if (!split_result || !isnumber(split_result))
	{
		free_wd(split_result);
		free(numbers);
		return 0;
	}
	return (1);
}

int	parseo(char **args, t_stacks *stacks)
{
	int		i;
	int		ln;
	int		*num;
	char	**spl_re;

	i = 1;
	ln = 0;
	num = malloc(sizeof(int) * 10000);
	if (!num)
		return (0);
	while (args[i] != NULL)
	{
		spl_re = ft_split(args[i], ' ');
		if (!check_split(spl_re, num))
			return (0);
		aux_s (spl_re, stacks, num, &ln);
		free_wd (spl_re);
		i++;
	}
	
	free (num);
	printf ("cantidad de args: %d\n", ln);
	return (1);
}
