/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:42:24 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/04 22:46:51 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isstringput(t_printf *pack, int buf)
{
	if (pack->punto == 1)
	{
		while (pack->s[++buf] && pack->preci != 0)
		{
			pack->preci--;
			write(1, &pack->s[buf], 1);
			pack->retorno++;
		}
	}
	else
	{
		while (pack->s[++buf])
		{
			write(1, &pack->s[buf], 1);
			pack->retorno++;
		}
	}
	pack->cont++;
}

void	ft_isstringminus(t_printf *pack, int buf)
{
	if (pack->preci != 0 && pack->preci < pack->len)
		pack->ancho -= pack->preci - 1;
	else if (pack->preci == 0 && pack->punto == 1)
		pack->ancho = pack->ancho + 1;
	else
		pack->ancho -= pack->len - 1;
	ft_isstringput(pack, buf);
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}
