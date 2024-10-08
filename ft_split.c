/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:58:29 by alvera-f          #+#    #+#             */
/*   Updated: 2024/10/04 12:03:07 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *str, char delimiter)
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

static char	**free_matrix(int position, char **matrix)
{
	while (position >= 0)
	{
		free(matrix[position--]);
	}
	free(matrix);
	return (NULL);
}

static char	*allocate_and_copy(const char *str, int start, size_t len)
{
	char	*substring;

	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (0);
	ft_strlcpy(substring, &str[start], len + 1);
	return (substring);
}

static char	**process_word(const char *s, char c, char **t)
{
	int	i;
	int	start;
	int	position;

	i = 0;
	position = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (s[i] == c || s[i] == '\0')
			{
				t[position] = allocate_and_copy(s, start, i - start);
				if (!t[position])
					return (free_matrix(position, t));
				position++;
			}
		}
	}
	return (t);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**t;

	words = ft_counter(s, c);
	t = (char **)ft_calloc((words + 1), sizeof(char *));
	if (!t)
		return (NULL);
	return (process_word(s, c, t));
}
