/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 00:41:19 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 00:12:05 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
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
