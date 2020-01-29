/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:02:57 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 19:12:02 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	a;

	a = 0;
	if (!(p = malloc(count * size)))
		return (0);
	while (a < (count * size))
	{
		*(p + a) = '\0';
		a++;
	}
	return (p);
}
