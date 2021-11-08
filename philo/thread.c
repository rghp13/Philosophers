/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/08 16:17:48 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sophia(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->ate < philo->info->fedlimit || philo->info->fedlimit == -1)
	{
		//p_eat(philo);
		//p_think(philo);
		//p_sleep(philo);
		philo->ate++;
		printf("Philo %d ate %d times\n", philo->id, philo->ate);
		usleep(1000);
	}
	return (NULL);
}

void	p_eat(t_philo *philo)
{
	take_forks(philo);
}