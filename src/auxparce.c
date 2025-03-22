/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxparce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:58:03 by alejogogi         #+#    #+#             */
/*   Updated: 2025/03/20 23:28:14 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	isnumber(char **str)
{
	int		j;
	char	**strs;
	int		j;

	strs = str;
	while (*strs != NULL)
	{
		j = 0;
		if ((*strs)[j] == '-' || (*strs)[j] == '+')
		{
			j++;
		}
		if ((*strs)[j] == '\0')
		{
			return (0);
			free_wd(str);
		}
		while ((*strs)[j] != '\0')
		{
			if (!isdigit((*strs)[j]))
			{
				free_wd(str);
				return (0);
			}
			j++;
		}
		strs++;
	}
	return (1);
} */
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
