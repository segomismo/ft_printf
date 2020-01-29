/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:24:13 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 19:19:23 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		a;
	unsigned const char	*b;
	unsigned const char	*c;

	a = 0;
	b = (unsigned const char *)s1;
	c = (unsigned const char *)s2;
	while (a < n)
	{
		if (*(b + a) != *(c + a))
			return (b[a] - c[a]);
		a++;
	}
	return (0);
}
