/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:19:47 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/20 22:27:35 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	uniquify(char *str, int len)
{
	int	i;
	int j;

	i = -1;
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

void	unionnprint(char *s1, int len1, char *s2, int len2)
{
	char	merge[len1 + len2 + 1];
	int		i;
	int		len;

	i = 0;
	while (*s1)
		merge[i++] = *s1++;
	while (*s2)
		merge[i++] = *s2++;
	len = uniquify(merge, i);
	i = 0;
	while (len--)
		write(1, &(merge[i++]), 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	unionnprint(argv[1], slen(argv[1]), argv[2], slen(argv[2]));
	write(1, "\n", 1);
	return (0);
}
