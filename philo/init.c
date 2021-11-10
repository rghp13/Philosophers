/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:27:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/10 15:20:50 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->display, NULL))
		return (-1);
	if (pthread_mutex_init(&info->is_eating, NULL))
		return (-1);
	info->isdead = 0;
	while (i < info->philo_num)
	{
		info->philo[i].id = i;
		info->philo[i].left = i;
		info->philo[i].right = i - 1;
		if (info->philo[i].right < 0)
			info->philo[i].right = info->philo_num - 1;
		info->philo[i].ate = 0;
		info->philo[i].last_ate = info->time;
		info->philo[i].info = info;
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	create_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		if (pthread_create(&info->philo[i].thread, NULL, sophia, \
		&info->philo[i]))
			return (i);
		i += 2;
	}
	i = 1;
	do_sleep(1);
	while (i < info->philo_num)
	{
		if (pthread_create(&info->philo[i].thread, NULL, sophia, \
		&info->philo[i]))
			return (i);
		i += 2;
	}
	return (0);
}

int	destroy_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		//pthread_detach(info->philo[i].thread);
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
