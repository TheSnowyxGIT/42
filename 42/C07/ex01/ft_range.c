/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:39:22 by apingard          #+#    #+#             */
/*   Updated: 2019/07/10 12:37:44 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int size;
	int *tab;
	int i;

	if (min >= max)
		return (NULL);
	size = max - min;
	tab = malloc(sizeof(*tab) * size);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		*(tab + i) = i + min;
	return (tab);
}
