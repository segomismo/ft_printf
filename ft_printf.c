/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:45:07 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/05 13:28:18 by ruben            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_casoslet(const char *format, t_printf *pack)
{
	if (format[pack->cont] == 'c')
		ft_preischar(pack);
	else if (format[pack->cont] == 's')
		ft_preisstring(pack);
	else if (format[pack->cont] == 'p')
		ft_preispointer(pack);
	else if (format[pack->cont] == 'd')
		ft_preisinter(pack);
	else if (format[pack->cont] == 'i')
		ft_preisinter(pack);
	else if (format[pack->cont] == 'u')
		ft_preisunint(pack);
	else if (format[pack->cont] == 'x')
		ft_prehexami(pack);
	else if (format[pack->cont] == 'X')
		ft_prehexama(pack);
	else if (format[pack->cont] == '%')
		ft_preporcentaje(pack);
}

void	ft_init(t_printf *pack)
{
	pack->minus = 0;
	pack->zero = 0;
	pack->ast = 0;
	pack->punto = 0;
	pack->ancho = 0;
	pack->preci = 0;
	pack->len = 0;
	pack->menos = 0;
}

void	ft_casosnum(const char *format, t_printf *pack)
{
	ft_init(pack);
	if (format[pack->cont] == '0' && pack->cont++)
		pack->zero = 1;
	if (format[pack->cont] == '-' && pack->cont++)
		pack->minus = 1;
	if (format[pack->cont] == '*' && pack->cont++)
		ft_asterisco(pack);
	while (ft_isdigit(format[pack->cont]) == 1)
		pack->ancho = pack->ancho * 10 + (format[pack->cont++] - 48);
	if (format[pack->cont] == '.' && pack->cont++)
		pack->punto = 1;
	if (format[pack->cont] == '*' && pack->cont++)
		ft_asterisco(pack);
	while (ft_isdigit(format[pack->cont]) == 1)
		pack->preci += pack->preci * 10 + ((int)(format[pack->cont++]) - 48);
	ft_casoslet(format, pack);
}

int		escriberaw(const char *format, t_printf *pack)
{
	while (format[pack->cont])
	{
		if (format[pack->cont] != '%')
		{
			pack->cont += write(1, &format[pack->cont], 1);
			pack->retorno++;
		}
		else
		{
			pack->cont++;
			if (ft_isalpha(format[pack->cont]) == 1)
				ft_casoslet(format, pack);
			else
				ft_casosnum(format, pack);
		}
	}
	return (pack->cont);
}

int		ft_printf(const char *format, ...)
{
	t_printf	*pack;
	int			fin;
	int			retorno;

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->cont = 0;
	pack->retorno = 0;
	va_start(pack->arg, format);
	fin = escriberaw(format, pack);
	retorno = pack->retorno;
	free(pack);
	return (retorno);
}
