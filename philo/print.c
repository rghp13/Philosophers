/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:49:30 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/08 18:50:00 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, const char *msg)
{
	int	time;

	time = (philo->info->time - get_time());
	pthread_mutex_lock(&philo->info->display);
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));
	pthread_mutex_unlock(&philo->info->display);
}