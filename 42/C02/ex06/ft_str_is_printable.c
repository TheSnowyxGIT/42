/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:29:44 by apingard          #+#    #+#             */
/*   Updated: 2019/07/04 14:50:07 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;
	int is_printable;

	is_printable = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] <= 126 && str[i] >= 32))
		{
			is_printable = 0;
		}
		i++;
	}
	return (is_printable);
}
