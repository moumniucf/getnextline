/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:16:19 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/07 13:56:37 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
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
	str = malloc((x + 1) * sizeof(char));
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
	return (str);
}
