/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/08 20:17:15 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sophia(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->ate < philo->info->fedlimit || philo->info->fedlimit == -1)
	{
		p_eat(philo);
		print_status(philo, SLEEP);
		do_sleep(philo->info->sleep)
		p_think(philo);
	}
	return (NULL);
}

void	p_eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->info->is_eating);
	philo->last_ate = philo->info->time - get_time();
	pthread_mutex_unlock(&philo->info->is_eating);
	print_status(philo, EAT);
	do_sleep(philo->info->eat);
	drop_forks(philo);
	philo->ate += 1;
	return ;
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->left]);
	pthread_mutex_unlock(&philo->info->forks[philo->right]);
}

void	take_forks(t_philo *philo)
{
	if (philo->left < philo->right)
	{
		pthread_mutex_lock(&philo->info->forks[philo->left]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->info->forks[philo->right]);
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->right]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->info->forks[philo->left]);
		print_status(philo, FORK);
	}
}
