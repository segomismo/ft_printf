/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:21:24 by rufranci          #+#    #+#             */
/*   Updated: 2019/12/03 17:14:21 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		a;
	unsigned int		b;
	char				*p;

	if (s == 0)
		return (0);
	a = ft_strlen(s);
	b = 0;
	if (start > a)
		return (ft_strdup(""));
	a = a - start;
	if (len < a)
	{
		if (!(p = malloc(sizeof(char) * len + 1)))
			return (0);
	}
	else if (!(p = malloc(sizeof(char) * a + 1)))
		return (0);
	while (*(s + start) && len > b)
	{
		*(p + b++) = *(s + start);
		start++;
	}
	*(p + b) = '\0';
	return (p);
}
