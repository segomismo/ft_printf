/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_%.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:35:23 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/10 17:04:16 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_porcenput(t_printf *pack, int buf)
{
	while (pack->s[++buf])
	{
		write(1, &pack->s[buf], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void	ft_porcenminus(t_printf *pack, int buf)
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
	ft_porcenput(pack, buf);
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}

void	ft_porcenzero(t_printf *pack, int buf)
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
	ft_porcenput(pack, buf);
}

void	ft_porcensino(t_printf *pack, int buf)
{
	pack->ancho -= pack->len - 1;
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
	ft_porcenput(pack, buf);
}

void	ft_porcenpreci(t_printf *pack, int buf)
{
	if (pack->menos == 1)
		pack->ancho--;
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
	ft_porcenput(pack, buf);
}

void	ft_porcentaje(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_porcenminus(pack, buf);
	else
	{
		if (pack->preci > 0)
			ft_porcenpreci(pack, buf);
		else if (pack->zero == 1)
			ft_porcenzero(pack, buf);
		else
			ft_porcensino(pack, buf);
	}
}

void	ft_preporcentaje(t_printf *pack)
{
	int	buf;

	pack->s = "%";
	buf = -1;
	pack->len = ft_strlen(pack->s);
	ft_porcentaje(pack, buf);
}
