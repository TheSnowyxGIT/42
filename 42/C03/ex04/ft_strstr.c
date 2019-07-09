/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apingard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:41:48 by apingard          #+#    #+#             */
/*   Updated: 2019/07/08 18:58:26 by apingard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int					ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));
		i++;
	}
	return (0);
}

char				*ft_strstr(char *str, char *to_find)
{
	int				i;
	char			*pt;

	if (ft_strlen(to_find) == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		pt = &str[i];
		if (ft_strncmp(pt, to_find, ft_strlen(to_find)) == 0)
		{
			return (pt);
		}
		i++;
	}
	return (0);
}
