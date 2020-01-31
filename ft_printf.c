/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:09:37 by rufranci          #+#    #+#             */
/*   Updated: 2020/01/31 13:44:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_casoslet(char *moha, t_printf *pack)
{
	if(moha[pack->cont] == 'c')//para chars
		ft_ischar(moha, pack);
	if(moha[pack->cont] == 's')//para strings
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
		ft_hexama(moha, pack);
}

int		escribe(char *moha, t_printf *pack)
{
	int	wis;

	wis = 0;
	while (moha[pack->cont] && moha[pack->cont] != '%')
	{
		pack->size += write(1, &moha[pack->cont], 1);
		pack->cont++;
	}
	if (moha[pack->cont] == '%')
	{
		pack->cont++;
		wis = ft_isalpha(moha[pack->cont]);
		if (wis == 1)
			ft_casoslet(moha, pack);
		else
			ft_casosnum(moha);
	}
	return(pack->cont);
}

int		ft_printf(const char *moha, ...)
{
	int			nuar;
	int			i;
	t_printf	*pack;
	char		buff[100];

	nuar = 0;
	if (!(pack = malloc(sizeof(t_printf))))
		return (-1);
	pack->size = 0;
	va_start(pack->arg, moha);
	i = 0;
	while (moha[i] && moha[i] != '%')
	{
		pack->size += write(1, &moha[i], 1);
		i++;
	}
	i++;
	if (moha[i] == 'c')
	{
		buff[nuar] = (char)va_arg(pack->arg, int);
	}
	pack->c = i;
	printf("%d", pack->c);
	printf("%c", buff[nuar]);
	printf("\n");
	va_end(pack->arg);
	return (i);
}

int		main(void)
{
	char	a;

	a = 'a';
	ft_printf("helloworld%c", a);
	return (0);
}
