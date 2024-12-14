/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:35:37 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/14 17:50:36 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	haveline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

char	*findetheline(char *buffer, int n)
{
	int		i;
	int		hvline;
	char	*ptr;

	if (!buffer || n == -1)
		return (NULL);
	if (haveline(buffer) == -1)
		return (ft_strdup(buffer));
	hvline = haveline(buffer);
	ptr = malloc((hvline + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < hvline)
	{
		ptr[i] = buffer[i];
		i++;
	}
	ptr[i] = '\n';
	ptr[i + 1] = '\0';
	return (ptr);
}

char	*afternewline(char *str)
{
	int		i;
	char	*ptr;
	int		x;
	int		y;
	int		xy;

	if (!str)
		return (NULL);
	y = ft_strlen(str);
	x = haveline(str);
	if (x == -1 || y == x + 1)
		return (free(str), NULL);
	xy = y - x;
	ptr = malloc((xy + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < xy)
	{
		ptr[i] = str[x + 1 + i];
		i++;
	}
	ptr[i] = '\0';
	return (free(str), ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*nextline;
	char		*ptr;
	int			readline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (haveline(buffer[fd]) == -1)
	{
		ptr = malloc(((size_t)BUFFER_SIZE) * sizeof(char) + 1);
		if (!ptr)
			return (NULL);
		readline = read(fd, ptr, BUFFER_SIZE);
		if (readline < 1)
		{
			free(ptr);
			break ;
		}
		ptr[readline] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], ptr);
		free(ptr);
	}
	nextline = findetheline(buffer[fd], readline);
	buffer[fd] = afternewline(buffer[fd]);
	return (nextline);
}
