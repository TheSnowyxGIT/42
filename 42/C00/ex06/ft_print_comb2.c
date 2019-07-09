/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:26:20 by apingard          #+#    #+#             */
/*   Updated: 2019/07/03 10:42:02 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers_comb2(int a, int b)
{
	int a1;
	int a2;
	int b1;
	int b2;

	a1 = a / 10;
	a2 = a % 10;
	b1 = b / 10;
	b2 = b % 10;
	if (a != 0 || b != 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	ft_putchar(a1 + 48);
	ft_putchar(a2 + 48);
	ft_putchar(' ');
	ft_putchar(b1 + 48);
	ft_putchar(b2 + 48);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_print_numbers_comb2(a, b);
			b++;
		}
		a++;
	}
}
