/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:41 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/11 19:23:43 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//haveline ==> nakhdo star b star
//getstar ==> y9ra lina star likayn f buufer w ydir lih return
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

	x = haveline(str);
	if (x == -1)
		return (NULL);
	y = ft_strlen(str);
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
	char *ptr;
	static char *array;
	int readline;
	char *nextline;
	while (haveline(array) == -1)
	{
		ptr = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!ptr)
			return (NULL);
		readline = read(fd, ptr, BUFFER_SIZE);
		if (readline < 1)
			break ;
		ptr[readline] = '\0';
		array = ft_strjoin(array, ptr);
		// printf("[%s , %d]", array, haveline(ptr));
	}
	nextline = findetheline(array);
	array = afternewline(array);
	// printf("[%s]", array);
	return (nextline);
}

int main()
{
	int fd = open("get_next_line.h", O_RDONLY, 0775);
	char *s;
	char *line;

	line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	while(line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
}

//==> step for get function

//1 ==> 