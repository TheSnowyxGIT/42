/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:08:43 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 00:11:42 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int val;

	val = 0;
	i = 0;
	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] < 0 && s1[i] != s2[i])
			return (-s2[i] - s1[i]);
		if (s2[i] < 0 && s1[i] != s2[i])
			return (s2[i] + s1[i]);
		if (s1[i] != s2[i])
			return ((s1[i] - s2[i]));
		i++;
	}
	return (0);
}
