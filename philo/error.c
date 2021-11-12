/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:09:00 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/12 17:14:59 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**
**
**
*/

void	error(int erno)
{
	if (erno == 0)
		printf("Error! Invalid argc\n");
	else if (erno == 1)
		printf("Error, invalid argument values\n");
	else if (erno == 2)
		printf("Error, invalid amount of philosophers\n");
	else if (erno == 3)
		printf("Error, failed to mutex init\n");
	else if (erno == 4)
		printf("Error, failed to init thread\n");
	exit(erno);
}

void	error_destroy_thread(t_info *info, int ret)
{
	int	i;

	i = 0;
	if (ret % 2 == 0)
	{
		while (i < ret)
		{
			pthread_detach(info->philo[i].thread);
			i += 2;
		}
		return ;
	}
	while (i < info->philo_num)
	{
		pthread_detach(info->philo[i].thread);
		i += 2;
	}
	i = 1;
	while (i < ret)
	{
		pthread_detach(info->philo[i].thread);
		i += 2;
	}
}
