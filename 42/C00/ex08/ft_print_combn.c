/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:52:07 by apingard          #+#    #+#             */
/*   Updated: 2019/07/04 19:45:59 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_pow(int n)
{
	int pow_number;
	int i;

	pow_number = 10;
	i = 0;
	while (i < n - 1)
	{
		pow_number = pow_number * 10;
		i++;
	}
	pow_number -= 1;
	return (pow_number);
}

int		ft_is_correct(int *nb, int n)
{
	int i;

	i = n - 1;
	while (i > 0)
	{
		if (nb[i] >= nb[i - 1])
		{
			return (0);
		}
		i--;
	}
	return (1);
}

void	ft_incrementation(int *nb, int n)
{
	int ind;

	ind = 0;
	nb[ind] += 1;
	while (nb[ind] >= 10)
	{
		if (ind + 1 > n - 1)
		{
			nb[ind] -= 1;
		}
		nb[ind + 1] += 1;
		nb[ind] = 0;
		ind++;
	}
}

void	ft_print_nb(int *nb, int n, int *first)
{
	int c;
	int a;

	if (*first != 1)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
	*first = 0;
	a = n - 1;
	while (a >= 0)
	{
		c = nb[a] + 48;
		write(1, &c, 1);
		a--;
	}
}

void	ft_print_combn(int n)
{
	int first;
	int compt;
	int nb[8];
	int pow_number;
	int i;

	i = 0;
	while (i < 8)
	{
		nb[i] = 0;
		i++;
	}
	first = 1;
	if (n == 1)
		ft_print_nb(nb, n, &first);
	compt = 0;
	pow_number = ft_pow(n);
	while (compt < pow_number)
	{
		ft_incrementation(nb, n);
		compt++;
		if (ft_is_correct(nb, n))
			ft_print_nb(nb, n, &first);
	}
}
