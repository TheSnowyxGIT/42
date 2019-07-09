/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:13:08 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 20:03:23 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				ind;
	unsigned int	i;

	ind = 0;
	while (dest[ind] != '\0')
		ind++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[i + ind] = src[i];
		i++;
	}
	dest[i + ind] = '\0';
	return (dest);
}
