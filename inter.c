/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:19:47 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/20 22:08:44 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	slen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	shiftleft(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		str[i] = str[i + 1];
}

int	uniquify(char *str)
{
	int	len;
	int	i;
	int j;

	i = -1;
	len = slen(str);
	while (++i < len)
	{
		j = i;
		while (j-- > 0)
		{
			if (str[i] == str[j])
			{
				shiftleft(&str[i--], --len);
				break;
			}
		}	
	}
	return (len);
}

void	findnprint(char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
		{
			write(1, &c, 1);
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = uniquify(argv[1]);
	printf("%s\tlen:%i\n", argv[1], len);
	while (len--)
		findnprint(argv[2], *(argv[1]++));
	write(1, "\n", 1);
	return (0);
}
