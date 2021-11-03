/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:42:41 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/03 20:15:33 by rponsonn         ###   ########.fr       */
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

int	parse(t_info *info, char **argv)
{
	int	i;

	i = 1;
	info->philo_num = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi
}
