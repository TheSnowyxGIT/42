/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 21:00:49 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 21:44:23 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_recur(int *i, int nb, int res)
{
	res = *i * *i;
	if (res == nb)
		return ;
	if (res > nb)
	{
		*i = 0;
		return ;
	}
	*i = *i + 1;
	ft_recur(i, nb, res);
}

int		ft_sqrt(int nb)
{
	int res;
	int i;

	res = 0;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	i = 2;
	ft_recur(&i, nb, res);
	return (i);
}
