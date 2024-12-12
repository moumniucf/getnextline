/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:37:57 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/12 18:38:45 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		x;

	x = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(x * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < x)
	{
		if (i < ft_strlen(s1))
		{
			str[i] = s1[i];
		}
		else
		{
			str[i] = s2[i - ft_strlen(s1)];
		}
		i++;
	}
	str[i] = '\0';
	return (free(s1), free(s2), str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;
	int		x;

	if (!str)
		return (NULL);
	x = ft_strlen(str);
	ptr = malloc((x + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
