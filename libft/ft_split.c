/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:16:56 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/21 13:31:32 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ojete(char const *s, int *d, char c)
{
	while (s[d[0]] == c)
		d[0]++;
	while (s[d[2]] == c)
		d[2]--;
}

int		primermalloc(char const *src, char c)
{
	int		a;
	int		vuelta;
	int		w;

	w = ft_strlen(src);
	a = 0;
	vuelta = 0;
	while (*(src + a))
	{
		if (a != 0 && *(src + a) == c && *(src + a - 1) != c && a < w)
			vuelta++;
		a++;
	}
	if (*(src + w - 1) == c)
		vuelta -= 1;
	return (vuelta + 2);
}

int		segundomalloc(char const *src, char c, int a)
{
	int		vuelta;

	vuelta = 0;
	while (src[a] != c && src[a++])
		vuelta++;
	return (vuelta + 1);
}

void	init(int *a, int *delmal, int *w)
{
	*a = 0;
	*delmal = 0;
	*w = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		d[3];

	if (s == '\0')
		return (0);
	init(&d[0], &d[1], &d[2]);
	if ((d[2] = ft_strlen(s) - 1) < 0)
	{
		p = (char **)malloc(sizeof(char *) * 1);
		p[0] = malloc(sizeof(char) * 1);
		p[0] = NULL;
		return (p);
	}
	ojete(s, d, c);
	if (!(p = (char **)malloc(sizeof(char *) * primermalloc(s, c))))
		return (0);
	while (d[0] <= d[2])
	{
		if (!(p[d[1]] = malloc(sizeof(char) * (segundomalloc(s, c, d[0])))))
			return (0);
		d[0] = ft_memccpy2(p[d[1]++], s, c, d[0]);
	}
	p[d[1]] = NULL;
	return (p);
}
