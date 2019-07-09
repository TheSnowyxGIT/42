/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:27:29 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 13:15:07 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		i;
	int		valint;
	float	valflt;
	int		res;

	res = 1;
	i = 1;
	while (i != nb)
	{
		valint = nb / i;
		valflt = (float)nb / (float)i;
		if (valflt == (float)valint)
		{
			if (i != 1 && i != nb)
				res = 0;
		}
		i++;
	}
	return (res);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	while (ft_is_prime(i) == 0)
		i++;
	return (i);
}
