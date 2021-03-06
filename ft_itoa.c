/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:31:07 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/16 16:31:07 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_size(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		size = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size = size + 1;
	}
	return (size);
}

static char	*to_alpha(long n, int size, char *str)
{
	if (n > 9)
		str = to_alpha(n / 10, size - 1, str);
	str[size - 1] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	l_n;

	l_n = (long)n;
	size = int_size(l_n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (l_n < 0)
	{
		l_n = l_n * -1;
		str[0] = '-';
	}
	str = to_alpha(l_n, size, str);
	str[size] = '\0';
	return (str);
}
