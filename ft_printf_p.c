/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:28:51 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/03 15:05:33 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ispointerput(t_printf *pack, int buf)
{
	pack->retorno += 2;
	write(1, "0", 1);
	write(1, "x", 1);
	while (pack->len < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->ancho--;
		pack->preci--;
	}
	while (pack->s[++buf])
	{
		write(1, &pack->s[buf], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void	ft_ispointerminus(t_printf *pack, int buf)
{
	pack->ancho -= pack->len;
	if (pack->punto == 1)
		pack->ancho--;
	while (11 < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->ancho--;
		pack->preci--;
	}
	ft_ispointerput(pack, buf);
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}

void	ft_ispointerzero(t_printf *pack, int buf)
{
	while (((pack->ancho--) - pack->len) > 0)
	{
		write(1, "0", 1);
		pack->retorno++;
	}
	ft_ispointerput(pack, buf);
}

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

void	ft_preispointer(t_printf *pack)
{
	unsigned long int	buf;

	buf = va_arg(pack->arg, unsigned long int);
	if (buf == 0 && pack->punto > 0)
		pack->s = " ";
	else
	{
		pack->s = ft_itohex3(buf);
		buf = -1;
		pack->len = ft_strlen(pack->s) + 1;
	}
	ft_ispointer(pack, buf);
	//liberar pack
}
