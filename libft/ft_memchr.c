/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:53:45 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/15 19:05:05 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	a;
	unsigned char	*b;

	a = 0;
	b = (unsigned char *)s;
	while (a < n)
	{
		if (b[a] == (unsigned char)c)
			return (&b[a]);
		a++;
	}
	return (0);
}
