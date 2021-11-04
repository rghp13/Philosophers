/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:09:00 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/04 15:13:23 by rponsonn         ###   ########.fr       */
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
		printf("Error, too many philosophers\n");
	exit(erno);
}
