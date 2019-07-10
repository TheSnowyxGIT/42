/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 01:37:35 by apingard          #+#    #+#             */
/*   Updated: 2019/07/10 00:31:51 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void    ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void    ft_swap(char **tab, int a, int b)
{
	char *temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

int        ft_is_lower(char *str1, char *str2)
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

int        ft_getind_valmin(char **tab, int size, int d_ind)
{
	int i;
	char *val;
	int index;

	if (d_ind == size - 1)
		return (d_ind);
	i = d_ind;
	val = tab[i];
	index = i;
	i++;
	while (i < size)
	{
		if (ft_is_lower(tab[i], val))
		{
			val = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int        main(int argc, char **argv)
{
	int a;
	int index;
	int size;

	a = 1;
	while (argv[a])
		a++;
	size = a;
	a = 1;
	while (argv[a])
	{
		index = ft_getind_valmin(argv, size, a);
		ft_swap(argv, a, index);
		a++;
	}
	a = 1;
	while (argv[a])
	{
		ft_putstr(argv[a++]);
		write(1, "\n", 1);
	}
	return (0);
}
