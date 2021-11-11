/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:54:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/11 23:15:23 by romain           ###   ########.fr       */
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

void	death_init(t_info *info, int i)
{
	int	time;

	pthread_mutex_lock(&info->check_dead);
	pthread_mutex_lock(&info->display);
	time = (get_time() - info->time);
	write(1, "[", 1);
	ft_putnbr(time);
	write(1, "] ", 2);
	ft_putnbr(info->philo[i].id);
	write(1, " ", 1);
	write(1, DIED, ft_strlen(DIED));
	pthread_mutex_unlock(&info->display);
	info->isdead = 1;
	pthread_mutex_unlock(&info->check_dead);
	pthread_mutex_unlock(&info->is_eating);
}

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
				death_init(info, i);
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
	if (info->fedlimit == -1)
		return (0);
	while (i < info->philo_num)
	{
		if (info->philo[i].ate < info->fedlimit)
			return (0);
		i++;
	}
	pthread_mutex_lock(&info->check_dead);
	info->isdead = 1;
	pthread_mutex_unlock(&info->check_dead);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		ret;

	if (argc != 5 && argc != 6)
		error(0);
	parse(&info, argv, argc);
	ret = init(&info);
	if (ret != 0)
		error(3);
	ret = create_threads(&info);
	if (ret != 0)
	{
		info.isdead = 1;
		error_destroy_thread(&info, ret);
		error(4);
	}
	monitor_threads(&info);
	destroy_threads(&info);
	return (0);
}
