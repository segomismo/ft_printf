/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:25:47 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/04 22:43:26 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isinterput(t_printf *pack, int buf)
{
	while (pack->s[++buf])
	{
		write(1, &pack->s[buf], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void	ft_isinterminus(t_printf *pack, int buf)
{
	pack->ancho -= pack->len - 1;
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
		pack->ancho--;
	}
	while (pack->len < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->ancho--;
		pack->preci--;
	}
	ft_isinterput(pack, buf);
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}
