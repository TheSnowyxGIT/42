/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:33:04 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 16:19:27 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dec_to_hex(unsigned char *hex, int nb)
{
	int div;
	int mod;
	int i;

	i = 0;
	div = nb;
	while (div != 0)
	{
		mod = div % 16;
		hex[i] = mod + (mod < 10) * '0' + (mod >= 10) * ('a' - 10);
		div = div / 16;
		i++;
	}
}

void	ft_print_hex(int size, int addr)
{
	unsigned char	hex[16];
	int				i;

	i = 0;
	while (i < 16)
	{
		hex[i] = '0';
		i++;
	}
	ft_dec_to_hex(hex, addr);
	i = size - 1;
	while (i >= 0)
	{
		write(1, &hex[i], 1);
		i--;
	}
}

int		ft_strlen(unsigned char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_print_hex_addr_vals(void *addr, int i, unsigned int *size)
{
	unsigned int a;

	write(1, "0000001", 7);
	ft_print_hex(8, (int)&addr[i * 16]);
	write(1, ":", 1);
	a = 0;
	while (a < 16)
	{
		if (a % 2 == 0)
			write(1, " ", 1);
		if (a > *size - 1)
		{
			write(1, "  ", 2);
		}
		else
		{
			ft_print_hex(2, ((unsigned char*)addr)[i * 16 + a]);
		}
		a++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int repet;
	int i;
	int b;
	int c;

	repet = ft_strlen(addr) / 16 + (ft_strlen(addr) % 16 != 0);
	i = 0;
	while (i < repet)
	{
		ft_print_hex_addr_vals(addr, i, &size);
		write(1, " ", 1);
		b = 0;
		while (b < 16 + ((int)size - 16) * ((int)size < 16))
		{
			c = ((unsigned char*)addr)[i * 16 + b];
			c = c * (c <= 126 && c >= 32) + 46 * (c > 126 || c < 32);
			write(1, &c, 1);
			b++;
		}
		write(1, "\n", 1);
		size -= 16;
		i++;
	}
	return (addr);
}
