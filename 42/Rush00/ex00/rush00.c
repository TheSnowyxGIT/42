/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:14:36 by apingard          #+#    #+#             */
/*   Updated: 2019/07/07 16:25:19 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_c1(void)
{
	ft_putchar('o');
}

void	print_c2(void)
{
	ft_putchar('|');
}

void	print_c3(void)
{
	ft_putchar('-');
}

void	print_space(void)
{
	ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		ax;
	int		ay;

	ay = 1;
	while (ay <= y)
	{
		ax = 1;
		while (ax <= x)
		{
			if ((ax == 1 || ax == x) && (ay == 1 || ay == y))
				print_c1();
			else if ((ax == 1 || ax == x) && (ay > 1 && ay < y))
				print_c2();
			else if ((ay == 1 || ay == y) && (ax > 1 && ax < x))
				print_c3();
			else
				print_space();
			ax++;
		}
		ft_putchar('\n');
		ay++;
	}
}
