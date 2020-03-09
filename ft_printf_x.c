/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:39:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/09 17:03:42 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_hexamiput(t_printf *pack, int buf)
{
	while (pack->s[++buf])
	{
		write(1, &pack->s[buf], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void	ft_hexamiminus(t_printf *pack, int buf)
{
	if (pack->preci != 0 && pack->preci < pack->len)
		pack->ancho -= pack->preci - 1;
	else if (pack->preci == 0 && pack->punto == 1)
		pack->ancho = pack->ancho + 1;
	else
		pack->ancho -= pack->len - 1;
	ft_hexamiput(pack, buf);
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}

void	ft_hexamizero(t_printf *pack, int buf)
{
	while (((pack->ancho--) - pack->len) > 0)
	{
		write(1, "0", 1);
		pack->retorno++;
	}
	ft_hexamiput(pack, buf);
}

void	ft_hexamisino(t_printf *pack, int buf)
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
	ft_hexamiput(pack, buf);
}

void	ft_hexamipreci(t_printf *pack, int buf)
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
	ft_hexamiput(pack, buf);
}

void    ft_hexami(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_hexamiminus(pack, buf);
	else
	{
		if (pack->preci > 0)
			ft_hexamipreci(pack, buf);
		else if (pack->zero == 1)
			ft_hexamizero(pack, buf);
		else
			ft_hexamisino(pack, buf);
	}
}


void    ft_prehexami(t_printf *pack)
{
	int	buf;

	buf = va_arg(pack->arg, int);
    if (buf == 0 && pack->punto > 0)
        pack->s = " ";
    else
    {
	pack->s = ft_itohex(buf);
    buf = -1;
    pack->len = ft_strlen(pack->s);
    ft_hexami(pack, buf);
    }
}
