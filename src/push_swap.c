/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:47 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/19 16:15:13 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

int main(int argc, char **argv)
{
	int result;
	char *n = "/n";
	
	if(argc < 2)
	{
	printf("numero de argumentos invalido\n");
	return 1;
	}	
	result = parceo(argv);
	if (result == 0)
	printf("Error\n");
	else 
	printf("resultado correcto%s", n);
	return(0);
}