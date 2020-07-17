/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:31:06 by rufranci          #+#    #+#             */
/*   Updated: 2020/07/10 13:44:16 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohex(unsigned	int a)
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

char	*ft_itohex3(unsigned long int a)
{
	unsigned long int	b;
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

char	*ft_itohex2(unsigned int a)
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

int		ft_isalpha(int a)
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
