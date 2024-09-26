/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:24:23 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/24 16:37:03 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
