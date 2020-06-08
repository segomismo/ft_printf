/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:42:24 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/05 13:39:18 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isstringzero(t_printf *pack, int buf)
{
	while (((pack->ancho--) - pack->len) > 0)
	{
		write(1, "0", 1);
		pack->retorno++;
	}
	ft_isstringput(pack, buf);
}

void	ft_isstringsino(t_printf *pack, int buf)
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
	ft_isstringput(pack, buf);
}

void	ft_isstringpreci(t_printf *pack, int buf)
{
	while (((pack->ancho - pack->preci) > 0) || (pack->ancho - pack->len > 0))
	{
		write(1, " ", 1);
		pack->retorno++;
		pack->ancho--;
	}
	ft_isstringput(pack, buf);
}

void	ft_isstring(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_isstringminus(pack, buf);
	else
	{
		if (pack->punto > 0)
		{
			ft_isstringpreci(pack, buf);
		}
		else if (pack->zero == 1)
			ft_isstringzero(pack, buf);
		else
			ft_isstringsino(pack, buf);
	}
}

void	ft_preisstring(t_printf *pack)
{
	void	*buff;
	int		buf;

	buf = -1;
	buff = va_arg(pack->arg, void *);
	if (buff == NULL)
		pack->s = "(null)";
	else
		pack->s = buff;
	pack->len = ft_strlen(pack->s);
	ft_isstring(pack, buf);
}
