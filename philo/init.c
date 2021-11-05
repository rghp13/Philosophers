/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:27:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/05 14:40:43 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_info *info)
{
	int	i;

	i = 0;
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
