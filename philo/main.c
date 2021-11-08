/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:54:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/08 19:58:20 by rponsonn         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		error(0);
	parse(&info, argv, argc);
	init(&info);
	create_threads(&info);
	//monitor_thread();
	return (0);
}
