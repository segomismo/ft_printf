/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:35:52 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 19:19:49 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		a;

	a = 0;
	while (*(s1 + a))
		a++;
	if (!(p = malloc(sizeof(char) * (a + 1))))
		return (0);
	a = 0;
	while (*(s1 + a))
	{
		*(p + a) = *(s1 + a);
		a++;
	}
	*(p + a) = '\0';
	return (p);
}
