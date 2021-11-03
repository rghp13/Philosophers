/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:58:32 by romain            #+#    #+#             */
/*   Updated: 2021/10/20 14:04:56 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**calculates the absolute difference between two ints
*/

int	ft_diff(int a, int b)
{
	if (a == b)
		return (0);
	else if (a > b)
		return (a - b);
	else
		return (b - a);
}
