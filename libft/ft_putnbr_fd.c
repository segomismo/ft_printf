/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:48:01 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/20 17:27:41 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	larg;
	char		a;

	larg = n;
	if (larg < 0)
	{
		write(fd, "-", 1);
		larg = larg * -1;
	}
	if (larg >= 10)
		ft_putnbr_fd(larg / 10, fd);
	a = larg % 10 + '0';
	write(fd, &a, 1);
}
