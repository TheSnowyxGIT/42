/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:49:54 by apingard          #+#    #+#             */
/*   Updated: 2019/07/10 10:57:39 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*allocation;

	i = 0;
	while (src[i])
		i++;
	allocation = malloc(sizeof(*allocation) * i);
	if (allocation == NULL)
		return (NULL);
	return (allocation);
}
