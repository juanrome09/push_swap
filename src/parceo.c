/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/17 20:25:32 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parceo(int argc, char **args)
{
    int 	i;
    int 	j;
	
    i = 1;
	j = 0;
		//si es cadena(string), atoi y split para tratarlos en la pila while (args[i])
		//split va antes para separar la cadena y tratar cada argumento			agrs[65]
	    //le hace falta tratar repetidos y mas cosas(comprobacion de datos subj)
		while (i < argc)
		{
			printf("Total de argc: %d\n ",i);
				ft_split(args[i], ' ');
				//reservar memoria para guardar lo que devuelve el split.
			printf("Numeros string: %s\n",args[i]);
			printf("%d\n",i);
			/* 	i++;
			while (args[i][j] != '\0')
			{
				if (args[i][j] == '-' || args[i][j] == '+')
				{
				j++;
				}
				if (!ft_isdigit(args[i][j]))
				{
				return 0;
				}
				j++;
			}
			ft_atoi(args[i]);
			j  = 0; */
			i++;
		}
		return(i);
}
int main(int argc, char **argv)
{
	long result;

	if(argc < 2)
	{
	printf("numero de argumentos invalido\n");
	return 1;
	}	
	result = parceo(argc,argv);
	if (result == 0)
	printf("esta mal");
	else 
	printf("resultado correcto\n");
	return(0);
}