/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:23:39 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/02 12:24:09 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ischar(t_printf *pack)
{
	char	buf;

	buf = va_arg(pack->arg, int);
	write(1, &buf, 1);
	pack->retorno++;
	pack->cont++;
}

void	ft_preischar(t_printf *pack)
{
	if (pack->minus == 1)
	{
		ft_ischar(pack);
		while (--pack->ancho > 0)
		{
			write(1, " ", 1);
			pack->retorno++;
		}
	}
	else
	{
		while (--pack->ancho > 0)
		{
			write(1, " ", 1);
			pack->retorno++;
		}
		ft_ischar(pack);
	}
}
