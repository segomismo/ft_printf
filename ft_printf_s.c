/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:42:24 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/03 15:44:26 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_preisstring(t_printf *pack)
{
	void	*buf;
	int		a;

	a = -1;
	buf = va_arg(pack->arg, void *);
	pack->s = buf;
	while (pack->s[++a])
	{
		write(1, &pack->s[a], 1);
		pack->retorno++;
	}
	pack->cont++;
}
