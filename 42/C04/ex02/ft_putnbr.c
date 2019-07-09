/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:02:31 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 12:50:21 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int nbr;

	nbr = nb;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(-(nbr / 10));
		ft_putnbr(-(nbr % 10));
		return ;
	}
	if (nbr >= 0 && nbr < 10)
	{
		ft_putchar(nbr + 48);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}
