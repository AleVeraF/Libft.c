/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:20 by alvera-f          #+#    #+#             */
/*   Updated: 2024/10/02 17:01:29 by alvera-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_length(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static void	convert_str(char *str, long num, int length)
{
	str[length] = '\0';
	if (num == 0)
		str[0] = '0';
	else
	{
		while (num != '\0')
		{
			str[--length] = (num % 10) + '0';
			num = num / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;
	long	num;

	length = ft_num_length(n);
	str = malloc(length + 1);
	num = n;
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	convert_str(str, num, length);
	return (str);
}
