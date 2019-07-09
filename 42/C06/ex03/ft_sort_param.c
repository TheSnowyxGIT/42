/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:49:31 by apingard          #+#    #+#             */
/*   Updated: 2019/07/09 12:35:24 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_is_lower(char *str1, char *str2)
{
	int i;
	
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			break;
		i++;
	}
	if (str1[i] == str2[i])
		return (0);
	if (str1[i] < str2[i])
		return (1);
	return (0);
}


int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		
	}
	
	return (0);
}

