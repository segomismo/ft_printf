/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:40:34 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/18 17:59:05 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*p;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(p = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1))))
		return (0);
	a = 0;
	b = 0;
	while (*(s1 + a))
	{
		*(p + a) = *(s1 + a);
		a++;
	}
	while (*(s2 + b))
	{
		*(p + a) = *(s2 + b);
		a++;
		b++;
	}
	*(p + a) = '\0';
	return (p);
}
