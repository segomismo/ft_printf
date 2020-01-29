/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:37:07 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/20 17:21:34 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	if (!(p = ft_strdup((char *)s)))
		return (0);
	while (s[i] != '\0')
	{
		p[i] = ((*f)(i, s[i]));
		i++;
	}
	p[i] = '\0';
	return (p);
}
