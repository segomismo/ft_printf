/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:31:06 by rufranci          #+#    #+#             */
/*   Updated: 2020/07/10 13:40:34 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

void		isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static int	negative(long int *n, int *i)
{
	int cont;

	cont = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		cont += 1;
		*i += 1;
	}
	return (cont);
}

char		*ft_itoa(long long int n)
{
	int						i;
	char					*p;
	int						cont;
	long int				num;
	unsigned long int		num2;

	i = 2;
	num = n;
	cont = negative(&num, &i);
	num2 = num;
	while (num /= 10)
		i++;
	if (!(p = malloc((i) * sizeof(char))))
		return (0);
	p[--i] = '\0';
	while (i-- > 0)
	{
		p[i] = num2 % 10 + '0';
		num2 = num2 / 10;
	}
	if (cont > 0)
		p[i + 1] = '-';
	return (p);
}

char		*ft_uitoa(unsigned int n)
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
