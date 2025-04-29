/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:54:19 by alejagom          #+#    #+#             */
/*   Updated: 2025/04/29 18:50:29 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <unistd.h>

long	ft_atoi_long(const char *str)
{
	long	res;
	int		sig;

	res = 0;
	sig = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (2147483648);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res * sig > INT_MAX || res * sig < INT_MIN)
			return (2147483648);
		str++;
	}
	return (res * sig);
}


/*
int	main(void)
{
	char	str[20];
	int		num;

	printf("Escribe un número en texto: ");
	scanf("%s", str);
	num = ft_atoi(str);
	printf("El número es: %d\n", num);
	return (0);
}
*/