/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:38:46 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 16:20:33 by apingard         ###   ########.fr       */
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
		hex[i] = (unsigned char)mod;
		div = div / 16;
		i++;
	}
}

int		ft_is_non_printable(char c)
{
	if (c <= 126 && c >= 32)
		return (0);
	return (1);
}

void	ft_hexnum_to_hexchar(unsigned char *hex)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (hex[i] < 10)
		{
			hex[i] = hex[i] + 48;
		}
		else
		{
			hex[i] = (hex[i] % 10) + 'a';
		}
		i++;
	}
}

void	ft_print_hex(unsigned char c)
{
	unsigned char	hex[2];
	char			bslash;

	ft_dec_to_hex(hex, c);
	ft_hexnum_to_hexchar(hex);
	bslash = 92;
	write(1, &bslash, 1);
	write(1, &hex[1], 1);
	write(1, &hex[0], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_non_printable(str[i]) == 1)
		{
			ft_print_hex((unsigned char)str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
