/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:27:25 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 10:31:22 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_lenstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	if (size == 0)
		return (ft_lenstr(src));
	i = 0;
	while (src[i])
	{
		if (i >= size - 1)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_lenstr(src));
}
