/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:26:44 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/18 18:03:57 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		comp(char const *s1, char const *set)
{
	int		b;
	int		a;

	a = 0;
	b = 0;
	while (*(s1 + a) && *(set + b))
	{
		if (*(s1 + a) == *(set + b))
		{
			b = 0;
			a++;
		}
		else
			b++;
	}
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	int		c;

	if (s1 == 0)
		return (0);
	a = 0;
	c = 0;
	b = comp(s1, set);
	a = ft_strlen(s1) - 1;
	while (a > 0 && *(set + c))
	{
		if (*(s1 + a) == *(set + c))
		{
			c = 0;
			a--;
		}
		else
			c++;
	}
	return (ft_substr(s1, b, a - b + 1));
}
