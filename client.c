/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:21:45 by iarrar            #+#    #+#             */
/*   Updated: 2023/07/17 16:47:47 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <stdio.h>

void	convert(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit++;
	}
}

void	splitstr(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		convert(pid, str[i]);
		i++;
	}
	convert(pid, str[i]);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	else
	{
		pid = ft_atoi(argv[1]);
		splitstr(pid, argv[2]);
	}
	return (0);
}
