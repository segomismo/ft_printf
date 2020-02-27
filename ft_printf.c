/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:45:07 by rufranci          #+#    #+#             */
/*   Updated: 2020/02/27 17:08:06 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void 	ft_hexami(t_printf *pack)//falta egstion de unsigned char
{
	int	buf;
	int		a;

	a = -1;
	buf = va_arg(pack->arg, int);
	pack->s = ft_itohex(buf);
	while (pack->s[++a])
	{
		write(1, &pack->s[a], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void 	ft_hexama(t_printf *pack)//falta egstion de unsigned char
{
	int	buf;
	int		a;

	a = -1;
	buf = va_arg(pack->arg, int);
	pack->s = ft_itohex2(buf);
	while (pack->s[++a])
	{
		write(1, &pack->s[a], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void	ft_isunint(t_printf *pack)
{
	unsigned int	buf;

	buf = va_arg(pack->arg, int);
	pack->s = ft_uitoa(buf);
	buf = 0;
	while (pack->s[buf])
	{
		write(1, &pack->s[buf], 1);
		pack->retorno++;
		buf++;
	}
	pack->cont++;
}

void	ft_isstring(t_printf *pack)
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

void	ft_ispointer(t_printf *pack)
{
	unsigned long int	buf;
	int					a;

	a = -1;
	buf = va_arg(pack->arg, unsigned long int);
	pack->s = ft_itohex3(buf);
	write(1, "0", 1);
	write(1, "x", 1);
	while (pack->s[++a])
	{
		write(1, &pack->s[a], 1);
		pack->retorno++;
	}
	free(pack->s);
	pack->cont++;
}

void	ft_isinterput(t_printf *pack, int buf)
{
	while (pack->s[++buf])
	{
		write(1, &pack->s[buf], 1);
		pack->retorno++;
	}
	pack->cont++;
}

void	ft_isinterminus(t_printf *pack, int buf)
{
	pack->ancho -= pack->len - 1;
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
		pack->ancho--;
	}
	ft_isinterput(pack, buf);
	while (pack->len < pack->preci)
	{
		write(1, "0", 1);
		pack->retorno++;
		pack->ancho--;
		pack->preci--;
	}
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
}

void	ft_isinterzero(t_printf *pack, int buf)
{
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
		pack->ancho--;
	}
	while (((pack->ancho--) - pack->len) > 0)
	{
		write(1, "0", 1);
		pack->retorno++;
	}
	ft_isinterput(pack, buf);
}

void	ft_isintersino(t_printf *pack, int buf)
{
	pack->ancho -= pack->len - 1;
	while (--pack->ancho > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
	if (pack->menos == 1)
	{
		write(1, "-", 1);
		pack->retorno++;
	}
	ft_isinterput(pack, buf);
}

void	ft_isinterpreci(t_printf *pack, int buf)
{
	while ((--pack->ancho - pack->preci - pack->len) > 0)
	{
		write(1, " ", 1);
		pack->retorno++;
	}
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
	ft_isinterput(pack, buf);
}

void	ft_isinter(t_printf *pack, int buf)
{
	if (pack->minus == 1)
		ft_isinterminus(pack, buf);
	else
	{
		if (pack->preci > 0)
			ft_isinterpreci(pack, buf);
		else if (pack->zero == 1)
			ft_isinterzero(pack, buf);
		else
			ft_isintersino(pack, buf);
	}
}

void	ft_preisinter(t_printf *pack)
{
	int	buf;

	buf = va_arg(pack->arg, int);
	if ((pack->zero == 1 || pack->preci > 0) && buf < 0)
	{
		pack->menos = 1;
		buf = buf * (-1);
	}
	pack->s = ft_itoa(buf);
	buf = -1;
	pack->len = ft_strlen(pack->s);
	ft_isinter(pack, buf);
}

void	ft_ischar(t_printf *pack)
{
	char	buf;

	buf = va_arg(pack->arg, int);
	write(1, &buf, 1);
	pack->retorno++;
	pack->cont++;
}

void	ft_preischar(t_printf *pack)
{
	if (pack->minus == 1)
	{
		ft_ischar(pack);
		while (--pack->ancho > 0)
		{
			write(1, " ", 1);
			pack->retorno++;
		}
	}
	else
	{
		while (--pack->ancho > 0)
		{
			write(1, " ", 1);
			pack->retorno++;
		}
		ft_ischar(pack);
	}
}

void	ft_casoslet(const char *format, t_printf *pack)
{
	if (format[pack->cont] == 'c')
		ft_preischar(pack);
	if (format[pack->cont] == 's')
		ft_isstring(pack);
	if (format[pack->cont] == 'p')
		ft_ispointer(pack);
	if (format[pack->cont] == 'd')//para deimales
		ft_preisinter(pack);
	if (format[pack->cont] == 'i')
		ft_preisinter(pack);
	if (format[pack->cont] == 'u')//para unsigner ints+
		ft_isunint(pack);
	if (format[pack->cont] == 'x')
		ft_hexami(pack);
	if (format[pack->cont] == 'X')
		ft_hexama(pack);
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
	/*if (format[pack->cont] == '*' && pack->cont++ && pack->rest--)
		pack->ast = 1;*/
	while (ft_isdigit(format[pack->cont]) == 1)
		pack->ancho = pack->ancho * 10 + (format[pack->cont++] - 48);
	if (format[pack->cont] == '.' && pack->cont++)
		pack->punto = 1;
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
				ft_casosnum(format, pack);//comprobar que no sea nulo, o porcentaje
		}
	}
	return (pack->cont);
}

int		ft_printf(const char *format, ...)
{
	t_printf	*pack;
	//void		*buf;//Este void sirve para meter los argumentos recibidos mientras los conviertes y los imprimes, al ser void, se puede castear facilente
	int			fin;

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->cont = 0;
	pack->retorno = 0;
	va_start(pack->arg, format);
	fin = escriberaw(format, pack);
	return (pack->retorno);
}
/*
int		main(void)
{
	char	a, *b, *c, *d, *e, f, g;
	int		a1, a2, a3, a4, a5;
	unsigned int	au1, au2, au3;
	int				hex1, hex2, hex3;
	unsigned char	hex4;
	int				total;

	a = 'a';
	b = "esto es b";
	c = "esto es c";
	d = "esto es d";
	e = "esto es e";
	f = 'f';
	g = 'g';
	a1 = 1;
	a2 = 22;
	a3 = -333;
	a4 = -4444;
	a5 = 56644;
	au1 = 0;
	au2 = -22;
	au3 = 4294967295;
	hex1 = 30000;
	hex2 = 0xFAFA;
	hex3 = 15;
	hex4 = 64;
	ft_printf("esto es lo que vale a(char)->%-111c<-\nesto es lo que vale b(string)->%s\nesto es lo que vale c(string)->%s\nesto es lo que vale d(string)->%s\nesto es lo que vale e(string)->%s\nesto es lo que vale f(char)->%c\nesto es lo que vale g(char)->%c\nesto es lo que vale un int de 1 cifras->%i\nesto es lo que vale un int de 2 cifras->%i\nesto es lo que vale un int de 3 cifras->%i\nesto es lo que vale un int de 4 cifras->%i\nesto es lo que vale un int de 5 cifras->%i\nesto es lo que vale un unsigned int de 1 cifras->%u\nesto es lo que vale un unsigned int de 2 cifras->%u\nesto es lo que vale un unsigned int de 3 cifras->%u\n", a, b , c, d, e, f, g, a1, a2, a3, a4, a5, au1, au2, au3);
	printf("PRI esto es lo que vale a(char)->%-111c<-\nPRI esto es lo que vale b(string)->%s\nPRI esto es lo que vale c(string)->%s\nPRI esto es lo que vale d(string)->%s\nPRI esto es lo que vale e(string)->%s\nPRI esto es lo que vale f(char)->%c\nPRI esto es lo que vale g(char)->%c\nPRI esto es lo que vale un int de 1 cifras->%i\nPRI esto es lo que vale un int de 2 cifras->%i\nPRI esto es lo que vale un int de 3 cifras->%i\nPRI esto es lo que vale un int de 4 cifras->%i\nPRI esto es lo que vale un int de 5 cifras->%i\nPRI esto es lo que vale un unsigned int de 1 cifras->%u\nPRI pri esto es lo que vale un unsigned int de 2 cifras->%u\nPRI esto es lo que vale un unsigned int de 3 cifras->%u\n", a, b , c, d, e, f, g, a1, a2, a3, a4, a5, au1, au2, au3);
	ft_printf("esto es 30000 en hexadecimal en minuscula: %x\nesto es FAFA en hexadecimal en minuscula: %x\nesto es 15 en hexadecimal en minuscula: %x\n", hex1, hex2, hex3);
	printf("PRI esto es 30000 en hexadecimal en minuscula: %x\nPRI esto es FAFA en hexadecimal en minuscula: %x\nPRI esto es 15 en hexadecimal en minuscula: %x\n", hex1, hex2, hex3);
	ft_printf("esto es 30000 en hexadecimal en Mayuscula: %X\nesto es FAFA en hexadecimal en Mayuscula: %X\nesto es 15 en hexadecimal en Mayuscula: %X\n", hex1, hex2, hex3);
	printf("PRI esto es 30000 en hexadecimal en Mayuscula: %X\nPRI esto es FAFA en hexadecimal en Mayuscula: %X\nPRI esto es 15 en hexadecimal en Mayuscula: %X\n", hex1, hex2, hex3);
	ft_printf("esto es 64 con unsigned char en hexadecimal en minuscula: %x\n", hex4);
	printf("PRI esto es 64 con unsigned char en hexadecimal en minuscula: %x\n", hex4);
	printf("PRIEsto es una prueba de tipo p con el printf: ->%p<-\n", b);
	ft_printf("Esto es una prueba de tipo p con el printf: ->%p<-\n", b);
	total = printf("Este es el printfnormal: ->%-111c<-\n", a);
	printf("Este es el valor del retorno de printf   : %i\n", total);
	ft_printf("Este es el ft_printf   : ->%-111c<-\n", a);
	return (0);
}
*/