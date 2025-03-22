/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/22 22:20:42 by juanrome         ###   ########.fr       */
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
	int		atoi;
	char	**split_result;
	char	**temp;

	i = 1;
	ln = 0;
	while (args[i] != NULL)
	{
		split_result = ft_split(args[i], ' ');
		temp = split_result;
		if (!isnumber(split_result) || !single_number(*split_result))
			return (0);
		while (*temp != NULL)
		{
			ln++;
			printf("argumento ya separado: %s\n", *temp);
			atoi = ft_atoi(*temp);
			push(&stacks->stack_a, atoi);
			printf("argumento convertido a int: %d\n", atoi);
			temp++;
		}
		free_wd(split_result);
		i++;
	}
	printf("cantidad de args: %d\n", ln);
	return (1);
}
