/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:20:44 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 19:21:43 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	a;
	unsigned int	b;

	if (dest == '\0' || src == '\0')
		return (0);
	a = 0;
	b = ft_strlen(src);
	if (dstsize == 0)
		return (b);
	while (*(src + a) && a < (dstsize - 1))
	{
		*(dest + a) = *(src + a);
		a++;
	}
	*(dest + a) = '\0';
	return (b);
}
