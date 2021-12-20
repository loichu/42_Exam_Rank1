/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:04:33 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/20 23:46:37 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	printf("Line 1\n%s", get_next_line(fd));
	printf("Line 2\n%s", get_next_line(fd));
}
