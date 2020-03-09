/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:58:01 by rufranci          #+#    #+#             */
/*   Updated: 2020/03/09 16:40:57 by rufranci         ###   ########.fr       */
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
#endif
/*
hacer free's de los mallocs de la funcion principal, a la que igualo el malloc de la secundaria
*/
