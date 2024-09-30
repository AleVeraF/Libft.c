/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:58:29 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/30 15:50:46 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(const char *str, char delimiter)
{
	int	count;
	int	i;
	int	is_token;

	is_token = 0;
	count = 0;
	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != delimiter && is_token == 0)
		{
			count++;
			is_token = 1;
		}
		else if (str[i] == delimiter)
			is_token = 0;
		i++;
	}
	return (count);
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
	t = (char **)malloc((count + 1) *sizeof(char *));
	if (t == NULL)
		return (0);
	i = 0;
	j = 0;
	start = -1;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter && start == -1)
			start = i;
		if ((str[i] == delimiter || str[i + 1] == '\0') && start != -1)
		{
			if (str[i] == delimiter)
				len = i - start;
			else
				len = i - start + 1;
			t[j] =(char *)malloc((len + 1) * sizeof(char));
			if (!t[j])
				return (NULL);
			ft_strlcpy(t[j], &str[start], len + 1);
			j++;
			start = -1;
		}	
		i++;
	}
	t[j] = NULL;
	return (t);
}
