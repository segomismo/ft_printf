/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:09:37 by rufranci          #+#    #+#             */
/*   Updated: 2020/01/29 16:35:25 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

int			ft_printf(const char *moha, ...)
{
	int	i;
	t_printf *pack;

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->size = 0;
	va_start(pack->arg, moha);
	i = 0;
	while (moha[i] && moha[i] != '%')
	{
		pack->size += write(1, &moha[i], 1);
		i++;
	}
	printf("%d", pack->size);

	return (i);
}

int 		main()
{
	ft_printf("helloworld");
	return (0);
}
