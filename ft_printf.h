/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:58:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/02/27 16:45:38 by rufranci         ###   ########.fr       */
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

typedef	struct t_printf {
	va_list arg;
	int		cont;//sirve para la posicion en la que esta
	int		retorno;
	char	*s;//lsun buffer para imprimir strings
	int		minus;
	int		zero;
	int		ast;
	int		punto;
	int		ancho;
	int		preci;
	int		len;
	int		menos;
}t_printf;

int		ft_isdigit(int c);
void	isnegative(int *n, int *negative);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strdup(const char *s1);
char	*ft_itohex(int	a);
char	*ft_itohex2(int	a);
char	*ft_itohex3(unsigned long int	a);
int		ft_isalpha(int a);
size_t	ft_strlen(const char *s);
#endif
/*
hacer free's de los mallocs de la funcion principal, a la que igualo el malloc de la secundaria
*/
