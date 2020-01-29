/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:56:02 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/22 12:55:05 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char*)hay);
	if (*hay == 0)
		return (0);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == hay[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char*)hay + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
