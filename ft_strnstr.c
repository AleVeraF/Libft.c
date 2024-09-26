/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:47:57 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/26 18:11:04 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *a, const char *b, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*b == 0)
		return ((char *) a);
	while (a[i] != '\0')
	{
		j = 0;
		while (b[j] != '\0' && a[i + j] == b[j] && (i + j) < n)
		{
			j++;
		}
		if (b[j] == '\0')
			return ((char *) &a[i]);
		i++;
	}
	return (NULL);
}
