/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:58:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/02/18 16:08:19 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct t_printf {
	va_list arg;
	int		size;//cuenta la cantidad de letras que ha impreso, el size total se puede hacer como cont+size.sieze solo lo cuento cuando imprimo mas de un caracter en los argumentos
	int		cont;//sirve para la posicion en la que esta
	int		rest;//sirve para restar los avances que no cuentan como impresion
	char	*s;//lsun buffer para imprimir strings
	int		minus;
	int		zero;
	int		ast;
	int		punto;
	int		ancho;
	int		preci;
	int		len;
	int		total;
}t_printf;
#endif
/*
hacer free's de los mallocs de la funcion principal, a la que igualo el malloc de la secundaria
*/

