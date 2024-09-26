/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:41:30 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/24 11:25:07 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	if (size > 0)
	{
		while (src[src_len] != '\0' && src_len < size -1)
		{
			dest[src_len] = src[src_len];
			src_len++;
		}
		dest[src_len] = '\0';
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	return (src_len);
}
