/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:38:11 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 19:21:57 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	rsl;

	i = ft_strlen(dest);
	rsl = ft_strlen(src);
	j = 0;
	if (size == 0)
		return (rsl);
	if (size <= i)
	{
		rsl += size;
		return (rsl);
	}
	else
		rsl += i;
	while (src[j] != '\0' && i < size - 1 && dest != src)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (rsl);
}
