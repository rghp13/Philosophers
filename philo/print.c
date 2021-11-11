/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:49:30 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/11 22:54:40 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, const char *msg)
{
	int	time;

	pthread_mutex_lock(&philo->info->check_dead);
	if (philo->info->isdead)
	{
		pthread_mutex_unlock(&philo->info->check_dead);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->check_dead);
	pthread_mutex_lock(&philo->info->display);
	time = (get_time() - philo->info->time);
	write(1, "[", 1);
	ft_putnbr(time);
	write(1, "] ", 2);
	ft_putnbr(philo->id);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));
	pthread_mutex_unlock(&philo->info->display);
	return (0);
}
