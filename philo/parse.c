/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:42:41 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/09 17:59:58 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**num of philo
**TTD
**eat
**sleep
**(optional) loop max
*/

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	isvalid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	parse(t_info *info, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (isvalid(argv[i++]) == 0)
			error(1);
	}
	info->philo_num = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->fedlimit = ft_atoi(argv[5]);
	else
		info->fedlimit = -1;
	info->time = get_time();
	if (info->philo_num > 200)
		error(2);
	return (0);
}
