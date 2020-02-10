/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:58:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/02/10 16:35:12 by rufranci         ###   ########.fr       */
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
	char	*s;//un buffer para imprimir strings
	int		minus;
	int		zero;
//	int		point;
//	int		ast;
	int		len;
}t_printf;
#endif
/*
Dudas:
¿Cómo libero memoria de un malloc creado dentro de una funcion?
Si es puntero, ¿cómo sé qué tipo de puntero es?
*/

