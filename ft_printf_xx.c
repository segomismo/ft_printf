/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:39:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/04 23:03:23 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexamiput(t_printf *pack, int buf)
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
	ft_hexamiput(pack, buf);
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}
