/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:39:28 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/01 19:37:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strjoin(char **s1, const char *s2)
{
	int		len;
	char	*ptr;

	if (*s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(*s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		free(*s1);
		return (NULL);
	}
	ft_memcpy(ptr, *s1, ft_strlen(*s1));
	ft_memcpy(ptr + ft_strlen(*s1), s2, ft_strlen(s2));
	ptr[len] = '\0';
	free(*s1);
	*s1 = NULL;
	return (ptr);
}
