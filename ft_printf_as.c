/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_as.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:28:51 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/03 19:19:51 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void    ft_asterisco(t_printf *pack)
{
    if(pack->punto > 0)
    {
		pack->preci = va_arg(pack->arg, int);
        if (pack->preci < 0)
        {
            pack->punto= 0;
            pack->preci = 0;
        }
    }
    else
    {
        pack->ancho = va_arg(pack->arg, int);
        if (pack->ancho < 0)
        {
            pack->ancho = pack->ancho * (-1);
	    	pack->minus = 1;
        }
    }
}
