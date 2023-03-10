/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:29:18 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/09 14:50:23 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i == 0)
		ft_putchar('0');
	else if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar((i % 10) + '0');
	}
	else
		ft_putchar(i + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	do_sleep(int time)
{
	int64_t	endtime;
	int64_t	current;

	endtime = get_time();
	endtime += time;
	current = 0;
	while (current < endtime)
	{
		usleep(50);
		current = get_time();
	}
	return ;
}
