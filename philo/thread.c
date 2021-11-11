/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/11 18:32:45 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sophia(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		if (p_eat(philo) == -1)
			break ;
		if (print_status(philo, SLEEP) == -1)
			break ;
		do_sleep(philo->info->sleep);
		if (print_status(philo, THINK) == -1)
			break ;
		if (philo->info->fedlimit > 0 && philo->ate >= philo->info->fedlimit)
			break ;
	}
	return (NULL);
}

int	p_eat(t_philo *philo)
{
	int	ret;

	take_forks(philo);
	ret = print_status(philo, EAT);
	if (ret == 0)
		do_sleep(philo->info->eat);
	drop_forks(philo);
	philo->ate += 1;
	return (ret);
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
	pthread_mutex_lock(&philo->info->is_eating);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->info->is_eating);
}
