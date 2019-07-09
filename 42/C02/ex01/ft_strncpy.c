/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:52:52 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 16:22:09 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				a;

	i = 0;
	a = 0;
	while (i < n)
	{
		if (src[i] == '\0')
		{
			a = 1;
		}
		if (a == 1)
		{
			dest[i] = '\0';
		}
		else
		{
			dest[i] = src[i];
		}
		i++;
	}
	return (dest);
}
