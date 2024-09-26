/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:53:25 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/24 11:27:05 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	const char	*end;

	end = str;
	while (*end != '\0')
	{
		end++;
	}
	while (end >= str)
	{
		if (*end == (char)c)
			return ((char *)end);
		end--;
	}
	if (c == '\0')
		return ((char *)end);
	return (NULL);
}
