/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:58:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/06/04 12:31:21 by ruben            ###   ########.fr       */
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
char	*ft_itoa_u(unsigned long int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strdup(const char *s1);
char	*ft_itohex(unsigned int	a);
char	*ft_itohex2(unsigned int	a);
char	*ft_itohex3(unsigned long int	a);
int		ft_isalpha(int a);
size_t	ft_strlen(const char *s);
void	ft_ischar(t_printf *pack);
void	ft_preischar(t_printf *pack);
void	ft_preisinter(t_printf *pack);
void	ft_isinter(t_printf *pack, int buf);
void	ft_isinterpreci(t_printf *pack, int buf);
void	ft_isintersino(t_printf *pack, int buf);
void	ft_isinterzero(t_printf *pack, int buf);
void	ft_isinterminus(t_printf *pack, int buf);
void	ft_isinterput(t_printf *pack, int buf);
void	ft_preispointer(t_printf *pack);
void	ft_ispointer(t_printf *pack, int buf);
void	ft_ispointerpreci(t_printf *pack, int buf);
void	ft_ispointerput(t_printf *pack, int buf);
void	ft_ispointerminus(t_printf *pack, int buf);
void	ft_ispointerzero(t_printf *pack, int buf);
void	ft_ispointersino(t_printf *pack, int buf);
void	ft_preisunint(t_printf *pack);
void	ft_isunint(t_printf *pack, int buf);
void	ft_isunintpreci(t_printf *pack, int buf);
void	ft_isunintsino(t_printf *pack, int buf);
void	ft_isunintzero(t_printf *pack, int buf);
void	ft_isunintminus(t_printf *pack, int buf);
void	ft_isunintput(t_printf *pack, int buf);
void	ft_preisstring(t_printf *pack);
void	ft_isstringput(t_printf *pack, int buf);
void	ft_isstringminus(t_printf *pack, int buf);
void	ft_isstringzero(t_printf *pack, int buf);
void	ft_isstringsino(t_printf *pack, int buf);
void	ft_isstringpreci(t_printf *pack, int buf);
void	ft_isstring(t_printf *pack, int buf);
void 	ft_prehexami(t_printf *pack);
void	ft_hexamaput(t_printf *pack, int buf);
void	ft_hexamaminus(t_printf *pack, int buf);
void	ft_hexamazero(t_printf *pack, int buf);
void	ft_hexamasino(t_printf *pack, int buf);
void	ft_hexamapreci(t_printf *pack, int buf);
void	ft_hexama(t_printf *pack, int buf);
void	ft_prehexama(t_printf *pack);
void	ft_porcenput(t_printf *pack, int buf);
void	ft_porcenminus(t_printf *pack, int buf);
void	ft_porcenzero(t_printf *pack, int buf);
void	ft_porcensino(t_printf *pack, int buf);
void	ft_porcenpreci(t_printf *pack, int buf);
void	ft_porcentaje(t_printf *pack, int buf);
void	ft_preporcentaje(t_printf *pack);
void	ft_tuputamadre(t_printf *pack);
void	ft_asterisco(t_printf *pack);
#endif
/*
hacer free's de los mallocs de la funcion principal, a la que igualo el malloc de la secundaria
*/
