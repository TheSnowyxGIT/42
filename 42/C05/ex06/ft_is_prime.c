/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:01:47 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 13:14:37 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_recur(int nb, int i, int *res)
{
	int		valint;
	float	valflt;

	valint = nb / i;
	valflt = (float)nb / (float)i;
	if (valflt == (float)valint)
	{
		if (i != 1 && i != nb)
			*res = 0;
	}
	if (i == nb)
		return ;
	i++;
	ft_recur(nb, i, res);
}

int		ft_is_prime(int nb)
{
	int res;
	int i;

	if (nb <= 1)
		return (0);
	res = 1;
	i = 1;
	ft_recur(nb, i, &res);
	return (res);
}
