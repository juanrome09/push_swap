/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by juanrome          #+#    #+#             */
/*   Updated: 2025/05/11 22:36:40 by juanrome         ###   ########.fr       */
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

int	check_split(char **split_result)
{
	if (!split_result || !split_result[0] || !isnumber(split_result))
	{
		free_wd(split_result);
		return (0);
	}
	return (1);
}

int	parseo(char **args, t_stacks *stacks)
{
	int		i;
	int		ln;
	int		*num;

	i = 1;
	ln = 0;
	num = NULL;
	while (args[i])
	{
		if (!parseo2(args[i], stacks, &num, &ln))
		{
			free(num);
			free_stacks(stacks);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(num);
	return (1);
}

int	parseo2(char *arg, t_stacks *stacks, int **num, int *ln)
{
	char	**spl_re;

	spl_re = ft_split(arg, ' ');
	if (!spl_re || !spl_re[0])
	{
		free_wd(spl_re);
		return (0);
	}
	if (!aux_s(spl_re, stacks, num, ln))
	{
		free_wd(spl_re);
		return (0);
	}
	free_wd(spl_re);
	return (1);
}
