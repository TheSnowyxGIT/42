/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:38:16 by apingard          #+#    #+#             */
/*   Updated: 2019/07/10 13:59:22 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int i;
	
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = max - min;
	range = malloc(sizeof(**range) * size);
	i = 0;
	while (i < max - min)
	{
		*(range + i) = malloc(sizeof(*range));
		if (&range[i] == NULL)
			return (-1);
		i++;
	}
	if (range == NULL)
		return (-1);
	i = -1;
	while (++i < size)
		**(range + i) = i + min;
	return (max - min);
}


int main()
{
	int **tab;
	int i;
	int min = 0;
	int max = 5;
	ft_ultimate_range(tab,min, max);
	i = 0;
	while (i < max - min)
	{
		printf("%d\n", tab[i][0]);
		i++;
	}
}

