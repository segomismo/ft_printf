/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:45:07 by rufranci          #+#    #+#             */
/*   Updated: 2020/02/03 17:29:50 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_ischar(char *moha, t_printf *pack)
{
	write(1, (va_arg(pack->arg, char)), 1);
	pack->cont++;
}

void	ft_casoslet(char *moha, t_printf *pack)
{
	if(moha[pack->cont] == 'c')//para chars
		ft_ischar(moha, pack);
	/*if(moha[pack->cont] == 's')//para strings
		ft_isstring(moha, pack);
	if(moha[pack->cont] == 'p')//para punteros
		ft_ispointer(moha, pack);
	if(moha[pack->cont] == 'd')//para deimales
		ft_isdecimal(moha, pack);
	if(moha[pack->cont] == 'i')//para ints
		ft_isinter(moha, pack);
	if(moha[pack->cont] == 'u')//para unsigner ints
		ft_isunint(moha, pack);
	if(moha[pack->cont] == 'x')//para hexadecimales con las letras en minuscula
		ft_hexami(moha, pack);
	if(moha[pack->cont] == 'X')//para hexadecimales con las letras en mayuscula
		ft_hexama(moha, pack);*/
}

void		escriberaw(char	*moha, t_printf *pack)
{
	int		wis;

	wis = 0;
	while (moha[pack->cont])
	{
		if (moha[pack->cont] != '%')
			pack->cont += write(1, &moha[pack->cont], 1);
		else (moha[pack->cont] == '%')
		{
		pack->cont++;
		wis = ft_isalpha(moha[pack->cont]);
		if (wis == 1)
			ft_casoslet(moha, pack);
		//else
		//	ft_casosnum(moha);//comprobar que no sea nulo, o porcentaje
		}
	}
}

int		ft_printf(const char *moha, ...)
{
	t_printf	*pack;
	void		*buf;//Este void sirve para meter los argumentos recibidos mientras los conviertes y los imprimes, al ser void, se puede castear facilente

	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->cont = 0;
	va_start(pack->arg, moha);
	escriberaw(moha, pack);
	return (pack->cont);
}

int		main(void)
{
	char	a;
	char	s;

	s = 'b';
	a = 'a';
	ft_printf("helloworld %c eoifjdkjg %c", a, s);
	return (0);
}
