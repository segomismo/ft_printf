/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:25:47 by rufranci          #+#    #+#             */
/*   Updated: 2020/07/10 13:38:50 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isinterzero(t_printf *pack, int buf)
{
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
		pack->ancho--;
	}
	while (((pack->ancho--) - pack->len) > 0)
	{
		write(1, "0", 1);
		pack->retorno++;
	}
	ft_isinterput(pack, buf);
}

void	ft_isintersino(t_printf *pack, int buf)
{
	pack->ancho -= pack->len - 1;
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
	}
	ft_isinterput(pack, buf);
}

void	ft_isinterpreci(t_printf *pack, int buf)
{
	if (pack->menos == 1)
		pack->ancho--;
	while (((pack->ancho - pack->preci) > 0) && (pack->ancho - pack->len > 0))
	{
		write(1, " ", 1);
		pack->retorno++;
		pack->ancho--;
	}
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
	}
	while (pack->len < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->preci--;
	}
	ft_isinterput(pack, buf);
}

void	ft_isinter(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_isinterminus(pack, buf);
	else
	{
		if (pack->preci > 0)
			ft_isinterpreci(pack, buf);
		else if (pack->zero == 1)
			ft_isinterzero(pack, buf);
		else
			ft_isintersino(pack, buf);
	}
}

void	ft_preisinter(t_printf *pack)
{
	int	buf;

	buf = va_arg(pack->arg, int);
	if (buf == 0 && pack->punto > 0)
		pack->s = " ";
	else
	{
		if (buf == -2147483648)
			buf = buf * (-1);
		if ((pack->zero == 1 || pack->preci > 0) && buf < 0)
		{
			pack->menos = 1;
			buf = buf * (-1);
		}
		pack->s = ft_itoa(buf);
		pack->mal = 1;
		buf = -1;
		pack->len = ft_strlen(pack->s);
	}
	ft_isinter(pack, buf);
}
