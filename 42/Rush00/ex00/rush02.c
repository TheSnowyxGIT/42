/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:41 by apingard          #+#    #+#             */
/*   Updated: 2019/07/07 16:25:48 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_c1(void)
{
	ft_putchar('B');
}

void	print_c2(void)
{
	ft_putchar('A');
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
			if (ay == 1 && (ax == 1 || ax == x))
				print_c2();
			else if (ay == y && (ax == 1 || ax == x))
				print_c3();
			else if ((ax > 1 && ax < x) && (ay > 1 && ay < y))
				print_space();
			else
				print_c1();
			ax++;
		}
		ft_putchar('\n');
		ay++;
	}
}
