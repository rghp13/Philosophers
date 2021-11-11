/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:24:29 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/11 18:09:35 by rponsonn         ###   ########.fr       */
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
# include <stdint.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"

struct	s_info;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	int				ate;
	int64_t			last_ate;
	struct s_info	*info;
	pthread_t		thread;
}			t_philo;

typedef struct s_info
{
	int				philo_num;
	int				ttd;
	int				eat;
	int				sleep;
	int				fedlimit;
	int				isdead;
	pthread_mutex_t	check_dead;
	int64_t			time;
	pthread_mutex_t	display;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	forks[200];
	t_philo			philo[200];
}				t_info;

int		main(int argc, char **argv);
int		parse(t_info *info, char **argv, int argc);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	error(int erno);
int64_t	get_time(void);
int		init(t_info *info);
void	*sophia(void *arg);
int		p_eat(t_philo *philo);
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
int		create_threads(t_info *info);
int		print_status(t_philo *philo, const char *msg);
void	do_sleep(int time);
void	monitor_threads(t_info *info);
void	print_death_info(t_info *info, int i);
int		all_philo_ate(t_info *info);
int		destroy_threads(t_info *info);
void	error_destroy_thread(t_info *info, int ret);

#endif
