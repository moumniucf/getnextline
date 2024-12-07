/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoumn <youmoumn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:41 by youmoumn          #+#    #+#             */
/*   Updated: 2024/12/07 16:58:13 by youmoumn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	haveline(char *s)
{
	// char bufer[100];
	// int fd = open("get_next_line_utils.c", O_RDONLY, 0775);
	// ssize_t p = read(fd, bufer, sizeof(bufer));
	int i = 0;
	while(s[i] && s[i] != '\n')
	{
		i++;
		if(s[i] == '\n')
			return(i);
	}
	return(0);
}
int x = 0;
void ft_ft(int n)
{
	n = n + 1;
}
int ft()
{
	return(x);
}
int main()
{
	int x = 5;
	ft_ft(x);
	printf("%d\n", x);
	char *s = "youssefmoumni\n\n\n";
	printf("%d\n", haveline(s));
	int fd = open("get_next_line.h", O_RDONLY);
	char  *readed = malloc(BUFFER_SIZE);
	read(fd, readed, BUFFER_SIZE);
	printf("[%s\n] == %d", readed, BUFFER_SIZE);
}
// char *get_next_line(int fd)
// {
// 	int i = 0;
// 	char *ptr;
// }