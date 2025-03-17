/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceo2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:04:51 by juanrome          #+#    #+#             */
/*   Updated: 2025/03/17 17:01:29 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parceo(char **args)
{
    int 	i;
    int     j;
    long 	all;
	
    i = 1;
    j = 0;
    
    while (args[i] != NULL)
    {
        while (args[i][j])
            {
                if (args[i][j] == '\0')
                {
                    all = ft_atoi(args[i]); 
                }
                j++;
            }
            j = 0;
            i++
    }
	return 1;	
}
int main(int argc, char **argv)
{
	int result;
	
	if(argc < 2)
	{
	printf("numero de argumentos invalido\n");
	return 1;
	}	
	result = parceo(argv);
	if (result == 0)
	printf("esta mal");
	else 
	printf("resultado correcto\n");
	return(0);
}

char* esCadena(const char *arg) {
    for (int i = 0; arg[i] != '\0'; i++) 
    }
    return 1