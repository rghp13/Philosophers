/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:54:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/09 17:16:25 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**memset, printf, malloc, free, write,
**usleep, gettimeofday, pthread_create,
**pthread_detach, pthread_join, pthread_mutex_init,
**pthread_mutex_destroy, pthread_mutex_lock,
**pthread_mutex_unlock
**should take between 5-6 args
**make custom usleep function that moves in smaller increments and returns
**once you're good
*/

#include "philo.h"

void	monitor_threads(t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(&info->is_eating);
		while (i < info->philo_num)
		{
			if (info->philo[i].last_ate + (int64_t)info->ttd < get_time())
			{
				print_status(&info->philo[i], DIED);
				info->isdead = 1;
				pthread_mutex_unlock(&info->is_eating);
				return ;
			}
			i++;
		}
		if (all_philo_ate(info) == 1)
		{
			pthread_mutex_unlock(&info->is_eating);
			return ;
		}
		pthread_mutex_unlock(&info->is_eating);
		do_sleep(5);
	}
}

int	all_philo_ate(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_num)
	{
		if (info->philo[i].ate < info->fedlimit)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		error(0);
	parse(&info, argv, argc);
	if (init(&info) == -1)
		return (-1);
	if (create_threads(&info) == -1)
		return (-1);
	monitor_threads(&info);
	destroy_threads(&info);
	//pthread_mutex_lock(&info.display);
	//pthread_mutex_unlock(&info.display);
	return (0);
}
