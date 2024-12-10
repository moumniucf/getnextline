/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:41 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/10 18:31:45 by youmoumn         ###   ########.fr       */
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
	ptr = malloc((hvline + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < hvline)
	{
		ptr[i] = buffer[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*afternewline(char *str)
{
	int		i;
	char	*ptr;
	int		x;
	int		y;
	int		xy;

	x = haveline(str);
	// if (x == -1)
	// 	return (NULL);
	y = ft_strlen(str);
	xy = (y - x);
	ptr = malloc((xy) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[(x + 1) + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	int i;
	char *array;
	static char *buuf;
	array = malloc(sizeof(BUFFER_SIZE));
	if (!array)
		return (NULL);
	return(array);
}

int main()
{
	char s[] = "youssef\nmoumni\n13337\n";
	printf("%s\n", afternewline(s));
}