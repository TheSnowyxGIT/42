/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:52:28 by apingard          #+#    #+#             */
/*   Updated: 2019/07/04 15:24:14 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_lowercase(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_lowercase(str[i]) == 1)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
