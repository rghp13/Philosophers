/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:27:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/08 15:12:52 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(info->display, NULL);
	pthread_mutex_init(info->is_eating, NULL);
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
		pthread_mutex_init(&info->forks[i], NULL);
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
		pthread_create(&info->philo[i].thread, NULL, sophia, &info->philo[i]);
		i++;
	}
	i = 0;
	while (i < info->philo_num)
		pthread_join(info->philo[i++].thread, NULL);
	return (0);
}
