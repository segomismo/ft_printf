/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:31:06 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/05 01:03:35 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

void	isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	negative = 0;
	isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (0);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	tmpn;
	int				len;
	char			*str;

	tmpn = n;
	len = 2;
	while (tmpn /= 10)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (0);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		a;

	a = 0;
	while (*(s1 + a))
		a++;
	if (!(p = malloc(sizeof(char) * (a + 1))))
		return (0);
	a = 0;
	while (*(s1 + a))
	{
		*(p + a) = *(s1 + a);
		a++;
	}
	*(p + a) = '\0';
	return (p);
}
