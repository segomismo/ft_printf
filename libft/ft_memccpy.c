/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:32:01 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/15 18:55:57 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	a;
	unsigned char	*b;
	unsigned char	*d;

	a = 0;
	b = dest;
	d = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (0);
	while (a < n)
	{
		if (d[a] == (unsigned char)c)
		{
			*(b + a) = *(d + a);
			return (&b[a + 1]);
		}
		*(b + a) = *(d + a);
		a++;
	}
	return (0);
}
