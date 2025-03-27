/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:47 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/27 13:34:50 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
	{
		printf("Error: No se proporcionaron suficientes argumentos.\n");
		return (1);
	}
	stacks = init_stacks();
	if (!stacks)
	{
		free_stacks(stacks);
		printf("Error: No se pudo inicializar las pilas.\n");
		return (1);
	}
	if (!parseo(argv, stacks))
	{
		printf("Error\n");
		return (1);
	}
	printf("Todos los argumentos se procesaron correctamente.\n");
	free_stacks(stacks);
	return (0);
}
