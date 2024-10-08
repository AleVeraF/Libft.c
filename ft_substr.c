/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:10:15 by alvera-f          #+#    #+#             */
/*   Updated: 2024/10/04 11:31:40 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*result;

	if (s == NULL)
	{
		return (NULL);
	}
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str_len = ft_strlen(s);
	if (start + len > str_len)
		len = str_len - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
