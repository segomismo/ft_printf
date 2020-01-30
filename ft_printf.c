/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:09:37 by rufranci          #+#    #+#             */
/*   Updated: 2020/01/30 17:36:44 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_printf(const char *moha, ...)
{
	int			nuar;
	int			i;
	t_printf	*pack;
	char		buff[100];

	nuar = 0;
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
	i++;
	if (moha[i] == 'c')
	{
		buff[nuar] = (char)pack->va_arg(arg, int);
	}
	//printf("%d", pack->c);
	printf("%c", buff[nuar]);

	return (i);
}

int		main(void)
{
	char	a;

	a = 'w';
	ft_printf("helloworld%c", a);
	return (0);
}
