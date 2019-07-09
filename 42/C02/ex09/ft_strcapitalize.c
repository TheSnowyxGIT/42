/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:16:50 by apingard          #+#    #+#             */
/*   Updated: 2019/07/06 01:07:21 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_lowercase(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}

int		ft_is_uppercase(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

void	ft_setuplowcase(char *str, int i, int uplow)
{
	if (uplow == 0)
	{
		if (ft_is_lowercase(str[i]) == 1)
		{
			str[i] = str[i] - 32;
		}
	}
	else
	{
		if (ft_is_uppercase(str[i]) == 1)
		{
			str[i] = str[i] + 32;
		}
	}
}

int		ft_is_not_alphanum(char c)
{
	if (ft_is_lowercase(c) == 0)
		if (ft_is_uppercase(c) == 0)
		{
			if (!(c <= '9' && c >= '0'))
				return (1);
		}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			ft_setuplowcase(str, i, 0);
			i++;
			continue;
		}
		if (ft_is_not_alphanum(str[i - 1]) == 1)
		{
			ft_setuplowcase(str, i, 0);
		}
		else
		{
			ft_setuplowcase(str, i, 1);
		}
		i++;
	}
	return (str);
}
