/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:38:30 by alvera-f          #+#    #+#             */
/*   Updated: 2024/09/27 15:44:16 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;

	if (!s1 || !s2)
		return (0);
	copy = malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!copy)
		return (0);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	ft_strlcpy(copy + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (copy);
}
