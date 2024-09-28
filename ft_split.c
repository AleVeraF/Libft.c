/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:58:29 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/28 19:43:46 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(const char *str, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
			count++;
		i++;
	}
	return (count + 1);
}
char **ft_split(char const *str, char delimiter)
{
	int	count;
	int	i;
	int	j;
	int	start;
	size_t len;
	char **t;

	count = ft_counter(str, delimiter);
	t = (char **)malloc(count *sizeof(char *));
	if (t == NULL)
		return (0);
	i = 0;
	j = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
		{
			len = i - start;
			t[j] =(char *)malloc((len + 1) * sizeof(char));
			ft_strlcpy(t[j], &str[start], len + 1);
			j++;
			start = i + 1;
		}
		i++;
	}
	len = i - start;
	t[j] = (char *)malloc((len + 1) *  sizeof(char));
	ft_strlcpy(t[j], &str[start], len + 1);
	t[count] = NULL;
	return (t);
}
int main() {
    const char *str = "Hola mundo esto es Carllos";
    char **tokens;
    int i;

    // Llamamos a la función ft_split
    tokens = ft_split(str, ' ');  // Dividimos la cadena en tokens usando ' ' como delimitador

    // Verificamos si la función devolvió NULL (en caso de error)
    if (tokens == NULL) {
        printf("Error: no se pudieron dividir los tokens.\n");
        return (1);  // Terminamos el programa si hay un error
    }

    // Imprimimos cada token hasta llegar al puntero NULL
    for (i = 0; tokens[i] != NULL; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
        free(tokens[i]);  // Liberamos la memoria de cada token después de usarlo
    }

    // Liberamos el array de punteros
    free(tokens);

    return 0;
}
