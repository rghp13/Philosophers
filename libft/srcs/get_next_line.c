/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:37:07 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/01 19:37:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fnext(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_staticclean(char **ptr)
{
	char	*ret;

	if (!ptr || !ptr[0])
		return (NULL);
	ret = ft_substr(*ptr, (ft_fnext(*ptr) + 1), ft_strlen(*ptr));
	free(*ptr);
	*ptr = NULL;
	return (ret);
}

int	get_next_line(int fd, char **line, int ret)
{
	char		data[GNL_BUFFER_SIZE + 1];
	static char	*ptr;

	if (fd < 0 || !line || GNL_BUFFER_SIZE < 1 || read(fd, data, 0) < 0)
		return (-1);
	ret = read(fd, data, GNL_BUFFER_SIZE);
	data[ret] = '\0';
	ptr = ft_gnl_strjoin(&ptr, data);
	if (ptr == NULL)
		return (-1);
	if (ft_strlen(ptr) == 0)
	{
		*line = ptr;
		return (0);
	}
	ft_loop(&ptr, &ret, &fd, data);
	if ((ft_fnext(ptr)) >= 0)
	{
		*line = ft_substr(ptr, 0, ft_fnext(ptr));
		ptr = ft_staticclean(&ptr);
		return (ft_im_out_of_lines(line, 1));
	}
	*line = ft_strdup(ptr);
	free(ptr);
	return (ft_im_out_of_lines(line, 0));
}

int	ft_im_out_of_lines(char **line, int output)
{
	if (*line == NULL)
		return (-1);
	else
		return (output);
}
/*
**Had to remove
**while ((ft_fnext(ptr) < 0) && ((ret = read(fd, data, GNL_BUFFER_SIZE)) > 0))
*/

int	ft_loop(char **ptr, int *ret, int *fd, char *data)
{
	while (ft_fnext(*ptr) < 0)
	{
		*ret = read(*fd, data, GNL_BUFFER_SIZE);
		if (*ret > 0)
		{
			data[*ret] = '\0';
			*ptr = ft_gnl_strjoin(ptr, data);
		}
		if (*ret == 0)
			return (0);
	}
	return (0);
}
