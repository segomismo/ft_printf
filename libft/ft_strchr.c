/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:14:30 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/22 12:33:36 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (*(s + a))
	{
		if (*(s + a) == (char)c)
			return ((char *)(s + a));
		a++;
	}
	if ((char)c == '\0')
		return ((char *)(s + a));
	return (0);
}
