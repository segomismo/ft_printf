/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:28:51 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/05 01:08:06 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ispointersino(t_printf *pack, int buf)
{
	pack->ancho -= pack->len;
	if (pack->punto == 1)
		pack->ancho--;
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
	ft_ispointerput(pack, buf);
}

void	ft_ispointerpreci(t_printf *pack, int buf)
{
	if (pack->punto == 1)
	{
		pack->ancho -= 3;
	}
	while ((pack->ancho - pack->preci > 0))
	{
		write(1, " ", 1);
		pack->retorno++;
		pack->ancho--;
	}
	while (11 < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->preci--;
	}
	ft_ispointerput(pack, buf);
}

void	ft_ispointer(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_ispointerminus(pack, buf);
	else
	{
		if (pack->preci > 0)
			ft_ispointerpreci(pack, buf);
		else if (pack->zero == 1)
			ft_ispointerzero(pack, buf);
		else
			ft_ispointersino(pack, buf);
	}
}

void	ft_tuputamadre(t_printf *pack)
{
	while ((pack->ancho - 2) > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
		pack->ancho--;
	}
	pack->retorno += 2;
	write(1, "0", 1);
	write(1, "x", 1);
	pack->cont++;
}

void	ft_preispointer(t_printf *pack)
{
	unsigned long int	buf;

	buf = va_arg(pack->arg, unsigned long int);
	if (buf == 0 && pack->punto > 0)
	{
		ft_tuputamadre(pack);
	}
	else
	{
		pack->s = ft_itohex3(buf);
		buf = -1;
		pack->len = ft_strlen(pack->s) + 1;
		ft_ispointer(pack, buf);
	}
}
