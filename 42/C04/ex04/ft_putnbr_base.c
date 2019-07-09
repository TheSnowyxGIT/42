/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:41:26 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 13:12:45 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_not_correct(char *base)
{
	int i;
	int b;

	i = 0;
	while (base[i])
	{
		b = 0;
		while (base[b])
		{
			if (i != b)
			{
				if (base[i] == base[b])
					return (1);
			}
			b++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

void	ft_print(long int nb, char *base)
{
	long int	nbr;
	int			sizeb;

	sizeb = ft_strlen(base);
	nbr = nb;
	if (nbr >= 0 && nbr < sizeb)
	{
		write(1, &base[nbr], 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_print(-nbr, base);
	}
	else
	{
		ft_print(nbr / sizeb, base);
		ft_print(nbr % sizeb, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_is_not_correct(base))
		return ;
	ft_print((long int)nbr, base);
}
