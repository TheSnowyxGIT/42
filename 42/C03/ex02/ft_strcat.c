/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:10:50 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 19:58:46 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int ind;
	int i;

	ind = 0;
	while (dest[ind] != '\0')
		ind++;
	i = 0;
	while (src[i])
	{
		dest[i + ind] = src[i];
		i++;
	}
	dest[i + ind] = '\0';
	return (dest);
}
