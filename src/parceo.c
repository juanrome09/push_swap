/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:20 by alejagom          #+#    #+#             */
/*   Updated: 2025/03/19 18:17:20 by juanrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_wd(char **words)
{
	int i;
    
    i = 0;
    while(words[i])
    {
    free(words[i]);
    i++;        
    }
    free(words);
}

int parceo(char **args) 
{
    int i;
    int j;
    long num;
    char **strs;
    char **split_result;
	char **tmp;

    i = 1;
    while (args[i] != NULL) 
	{
        split_result = ft_split(args[i], ' ');
		strs = split_result;
        
        while (*strs == NULL)
        {
            strs++;
            free(split_result);
            return 0;
        }
        
    printf("esto bota %s\n", (*strs));
        while (*strs != NULL)
		{
            j = 0;
            if ((*strs)[j] == '-' || (*strs)[j] == '+') {
                j++;
            }
            while ((*strs)[j] != '\0') 
			{
                if (!isdigit((*strs)[j]))
				{
                    free_wd(split_result);
                    return 0;
                }
                j++;
            }
            strs++;
        }
        
        free_wd(split_result);
        i++;
    }
  /*   num = ft_atoi(*strs);
    printf("esto bota %ld\n", num); */
    return 1; 
}
/* int parceo(char **args) {
    int i = 1;    // Variable para iterar sobre los argumentos
    char **split_result;  // Variable reutilizable
    char *current;  // Apunta al string actual a procesar

    while (args[i] != NULL) {
        split_result = ft_split(args[i], ' '); // Divide el string por espacios
        if (!split_result || !*split_result) { // Verifica si el resultado es válido
            free(split_result);
            return 0;
        }

        current = *split_result;
        while (current != NULL) {
            if (!esNumero(current)) { // Función auxiliar para validar números
                free_wd(split_result);
                return 0;
            }
            current = *(++split_result); // Avanza al siguiente string
        }

        free_wd(split_result);
        i++;
    }

    return 1;
}

// Función auxiliar para verificar si un string es un número válido
int esNumero(char *str) {
    int j = 0;

    if (str[j] == '-' || str[j] == '+') {
        j++; // Permitir signo al inicio
    }

    while (str[j] != '\0') {
        if (!isdigit(str[j])) {
            return 0; // No es un número válido
        }
        j++;
    }

    return 1; // Es un número válido
}
 */