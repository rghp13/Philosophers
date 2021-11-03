/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_str_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:33:34 by rponsonn          #+#    #+#             */
/*   Updated: 2021/10/29 13:42:48 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BYTE 4

/*
**takes a hex string and returns an unsigned int
**as it returns an unsigned int it will not deal with strings longer than 8byte
**returns 0 if no string is passed
**for the future, check that the hex values are legal and maybe make str const
**hex check returns 1 if all chars are hex valid, 0 otherwise
*/

int	ft_check_if_hex(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] >= 'a' && str[i] <= 'f')
			i++;
		else if (str[i] >= 'A' && str[i] <= 'F')
			i++;
		else
			return (0);
	}
	return (1);
}

unsigned int	ft_hex_str_to_int(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (str == NULL)
		return (0);
	while (i < 8)
	{
		result <<= BYTE;
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_toupper(str[i]);
			result |= (str[i] - 'A' + 10);
		}
		else
			result |= (str[i] - '0');
		i++;
	}
	return (result);
}
