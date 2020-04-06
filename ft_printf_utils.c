/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:31:06 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/10 12:46:25 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
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

char	*ft_itohex(unsigned int	a)
{
	unsigned int		b;
	int					len;
	char				*ret;

	len = 2;
	b = a;
	while (b /= 16)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (0);
	ret[--len] = '\0';
	while (len--)
	{
		if ((a % 16) < 10)
			ret[len] = (a % 16) + '0';
		else
			ret[len] = (a % 16) - 10 + 'a';
		a = a / 16;
	}
	return ((char*)ret);
}

char	*ft_itohex3(unsigned long int	a)//convierte un int en una cadena de ints en base 16
{
	unsigned long int		b;
	int		len;
	char	*ret;

	len = 2;
	b = a;
	while (b /= 16)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (0);
	ret[--len] = '\0';
	while (len--)
	{
		if ((a % 16) < 10)
			ret[len] = (a % 16) + '0';
		else
			ret[len] = (a % 16) - 10 + 'a';
		a = a / 16;
	}
	return ((char*)ret);
}

char	*ft_itohex2(unsigned int	a)//convierte un int en una cadena de ints en base 16
{
	unsigned int		b;
	int					len;
	char				*ret;

	len = 2;
	b = a;
	while (b /= 16)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len)))
		return (0);
	ret[--len] = '\0';
	while (len--)
	{
		if ((a % 16) < 10)
			ret[len] = (a % 16) + '0';
		else
			ret[len] = (a % 16) - 10 + 'A';
		a = a / 16;
	}
	return ((char*)ret);
}

int	ft_isalpha(int a)
{
	if (a < 'A' || (a > 'Z' && a < 'a') || a > 'z')
		return (0);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (*(s + a))
		a++;
	return (a);
}
