/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:46:11 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 15:57:14 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_length_error(char *base)
{
	int i;
	int b;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
				|| base[i] == '\f' || base[i] == '\r')
			return (0);
		b = 0;
		while (base[b])
		{
			if (base[i] == base[b] && b != i)
				return (0);
			b++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		ft_error(char *str, char *base)
{
	int i;
	int j;
	int a;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	j = i;
	while (str[j])
	{
		a = 0;
		while (base[a] && (str[j] != base[a] ||
					(str[j] == '+' || str[j] == '-')))
			a++;
		if (str[j] != base[a] && str[j] != '+' && str[j] != '-')
			return (0);
		j++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		ft_getid_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && c != base[i])
		i++;
	if (base[i] == '\0')
		return (-1);
	return (i);
}

void	ft_setneg(int *res, int compt)
{
	if (compt % 2 == 1)
		*res = -*res;
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int negcompt;
	int res;

	negcompt = 0;
	if (ft_error(str, base) == 0 || ft_length_error(base) == 0)
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			negcompt++;
		i++;
	}
	res = 0;
	while (str[i] && ft_getid_base(str[i], base) != -1)
	{
		res = (res * ft_length_error(base)) + ft_getid_base(str[i], base);
		i++;
	}
	ft_setneg(&res, negcompt);
	return (res);
}
