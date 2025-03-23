/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/24 00:10:58 by juanrome         ###   ########.fr       */
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

int	parceo(char **args, t_stacks *stacks)
{
	int		i;
	int		ln;
	int		*numbers;
	char	**split_result;

	i = 1;
	ln = 0;
	numbers = malloc(sizeof(int) * 1000);
	if (!numbers)
		return (0);
	while (args[i] != NULL)
	{
		split_result = ft_split(args[i], ' ');
		if (!split_result)
			return (0);
		aux_s (split_result, stacks, numbers, &ln);
		free_wd (split_result);
		i++;
	}
	free (numbers);
	printf ("cantidad de args: %d\n", ln);
	return (1);
}
