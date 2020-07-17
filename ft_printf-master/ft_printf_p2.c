/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:28:51 by rufranci          #+#    #+#             */
/*   Updated: 2020/07/10 13:40:54 by ruben            ###   ########.fr       */
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
	if (pack->mal == 1)
	{
		free(pack->s);
		pack->mal = 0;
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
