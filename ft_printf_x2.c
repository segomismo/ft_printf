/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:48:58 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/05 01:08:47 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexamazero(t_printf *pack, int buf)
{
	while (((pack->ancho--) - pack->len) > 0)
	{
		write(1, "0", 1);
		pack->retorno++;
	}
	ft_hexamaput(pack, buf);
}

void	ft_hexamasino(t_printf *pack, int buf)
{
	if (pack->preci != 0 && pack->preci < pack->len)
		pack->ancho -= pack->preci;
	else if (pack->preci == 0 && pack->punto == 1)
		pack->ancho = pack->ancho + 1;
	else
		pack->ancho -= pack->len - 1;
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
	ft_hexamaput(pack, buf);
}

void	ft_hexamapreci(t_printf *pack, int buf)
{
	while (((pack->ancho - pack->preci) > 0) && (pack->ancho - pack->len > 0))
	{
		write(1, " ", 1);
		pack->retorno++;
		pack->ancho--;
	}
	while (pack->len < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->preci--;
	}
	ft_hexamaput(pack, buf);
}

void	ft_hexama(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_hexamaminus(pack, buf);
	else
	{
		if (pack->punto == 1)
			ft_hexamapreci(pack, buf);
		else if (pack->zero == 1)
			ft_hexamazero(pack, buf);
		else
			ft_hexamasino(pack, buf);
	}
}

void	ft_prehexama(t_printf *pack)
{
	int	buf;

	buf = va_arg(pack->arg, int);
	if (buf == 0 && pack->punto > 0)
		pack->s = " ";
	else
	{
		pack->s = ft_itohex2(buf);
		buf = -1;
		pack->len = ft_strlen(pack->s);
	}
	ft_hexama(pack, buf);
}
