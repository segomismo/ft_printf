/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:20:04 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 13:20:25 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memccpy2(char *dest, char const *src, char c, int i)
{
	int	y;

	if (dest == src)
		return (0);
	y = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
		{
			dest[y] = '\0';
			while (*(src + i + 1) == c)
				i++;
			return (i + 1);
		}
		dest[y] = src[i];
		i++;
		y++;
	}
	*(dest + y) = '\0';
	return (i + 1);
}
