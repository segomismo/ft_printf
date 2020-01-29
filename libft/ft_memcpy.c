/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:53:11 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/18 11:57:13 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = dest;
	c = (unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (a < n)
	{
		*(b + a) = *(c + a);
		a++;
	}
	return (dest);
}
