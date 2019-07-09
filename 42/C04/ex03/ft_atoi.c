/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 00:16:26 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 15:53:04 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int cneg;
	int neg;
	int val;

	neg = 1;
	cneg = 0;
	i = 0;
	while (str[i] && ft_is_isspace(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		if (str[i++] == '-')
			cneg++;
	if (cneg % 2 == 1)
		neg = -neg;
	val = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		val = (val * 10) + (str[i] - '0');
		i++;
	}
	return (val * neg);
}
