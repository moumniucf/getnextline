/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:41 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/09 12:53:12 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	haveline(char *s)
{
	int	i;
	if (!s)
		return(-1);
	i = 0;
	while(s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return(-1);
}

char	*get_next_line(int fd)
{
	int i;
	char *ptr;
	return(NULL);
}
int main(int ac, char **av)
{
	(void) ac;
	int i = 0;
	char *ptr;
	ptr = malloc(sizeof(BUFFER_SIZE));
	int fd = open(av[1], O_RDONLY);
	read(fd, ptr, BUFFER_SIZE);
	printf("%s\n", ptr);
	printf("%zd\n",read(fd, ptr, BUFFER_SIZE));
}