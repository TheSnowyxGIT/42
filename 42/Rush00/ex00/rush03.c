/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:15:33 by apingard          #+#    #+#             */
/*   Updated: 2019/07/07 16:25:56 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_c1(void)
{
	ft_putchar('A');
}

void	print_c2(void)
{
	ft_putchar('B');
}

void	print_c3(void)
{
	ft_putchar('C');
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
			if (ax == 1 && (ay == 1 || ay == y))
				print_c1();
			else if (ax == x && (ay == 1 || ay == y))
				print_c3();
			else if ((ax > 1 && ax < x) && (ay > 1 && ay < y))
				print_space();
			else
				print_c2();
			ax++;
		}
		ft_putchar('\n');
		ay++;
	}
}
