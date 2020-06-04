/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:22:18 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/04 12:48:54 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_itoa_u(unsigned long int n)
{
	unsigned long int		tmpn;
	int						len;
	char					*str;

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
