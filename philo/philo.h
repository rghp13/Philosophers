/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:24:29 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/03 20:08:15 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_info;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	int				ate;
	int64_t			last_ate;
	struct s_info	*info;
}			t_philo;

typedef struct s_info
{
	int				philo_num;
	int				ttd;
	int				eat;
	int				sleep;
	int				fedlimit;
	int				currentfed;
	int64_t			time;
	pthread_mutex_t	display;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	forks[200];
	t_philo			philo[200];
}				t_info;

int	main(int argc, char **argv);
int	parse(t_info *info, char **argv);
int	ft_atoi(const char *str);

#endif
