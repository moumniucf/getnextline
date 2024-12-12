/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:41 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/12 18:28:40 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	haveline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

char	*findetheline(char *buffer)
{
	int		i;
	int		hvline;
	char	*ptr;

	if (!buffer)
		return (NULL);
	hvline = haveline(buffer);
	if (hvline == -1)
	{
		return (ft_strdup(buffer));
	}
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
		return (NULL);
	xy = (y - x);
	ptr = malloc((xy) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < xy)
	{
		ptr[i] = str[(x + 1) + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*nextline;
	char		*ptr;
	int			readline;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (haveline(buffer) == -1)
	{
		ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
		readline = read(fd, ptr, BUFFER_SIZE);
		if (readline <= 0)
		{
			free(ptr);
			break ;
		}
		ptr[readline] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	nextline = findetheline(buffer);
	tmp = buffer;
	buffer = afternewline(buffer);
	return (free(tmp), nextline);
}

// void	leaks()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	int fd = open("get_next_line.h", O_RDONLY, 0775);
// 	char *line;
// 	line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s", line);
// 		// free(line);
// 		line = get_next_line(fd);
// 		printf("==> %p\n", line);
// 	}
// 	atexit(leaks);
// }