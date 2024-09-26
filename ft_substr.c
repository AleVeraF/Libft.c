/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:10:15 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/26 18:24:44 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*result;

	if (s == NULL || start >= ft_strlen(s))
		result = (char *)malloc(1);
		result[0] = '\0';
		return (result);
	str_len = ft_strlen(s);
	if (start + len > str_len)
		len = str_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
