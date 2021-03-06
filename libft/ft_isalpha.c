/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufranci <rufranci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:58:19 by rufranci          #+#    #+#             */
/*   Updated: 2019/11/05 12:32:29 by rufranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int a)
{
	if (a < 'A' || (a > 'Z' && a < 'a') || a > 'z')
		return (0);
	return (1);
}
