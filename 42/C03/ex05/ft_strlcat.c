/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:58:46 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 20:52:41 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	sized;

	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	sized = ft_strlen(dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && j < (size - 1 - sized))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (sized + ft_strlen(src));
}
