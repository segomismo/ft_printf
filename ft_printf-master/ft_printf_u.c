/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:09:29 by rufranci          #+#    #+#             */
/*   Updated: 2020/07/10 12:53:31 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isunintzero(t_printf *pack, int buf)
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

void	ft_isunintsino(t_printf *pack, int buf)
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
	ft_isunintput(pack, buf);
}

void	ft_isunintpreci(t_printf *pack, int buf)
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
	ft_isunintput(pack, buf);
}

void	ft_isunint(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_isunintminus(pack, buf);
	else
	{
		if (pack->preci > 0)
			ft_isunintpreci(pack, buf);
		else if (pack->zero == 1)
			ft_isunintzero(pack, buf);
		else
			ft_isunintsino(pack, buf);
	}
}

void	ft_preisunint(t_printf *pack)
{
	unsigned int	buf;

	buf = va_arg(pack->arg, unsigned int);
	if (buf == 0 && pack->punto > 0)
		pack->s = " ";
	else
	{
		if ((pack->zero == 1 || pack->preci > 0) && buf < 0)
		{
			pack->menos = 1;
			buf = buf * (-1);
		}
		if (buf == 4294967295)
			pack->s = "4294967295";
		else
		{
			pack->s = ft_itoa_u(buf);
			pack->mal = 1;
		}
		buf = -1;
		pack->len = ft_strlen(pack->s);
	}
	ft_isunint(pack, buf);
}
