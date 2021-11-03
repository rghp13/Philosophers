/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:58:35 by rponsonn          #+#    #+#             */
/*   Updated: 2021/11/01 13:42:12 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**split string s along occurences of c. returns array of strings
*/

static char	*ft_get_string(int *end, const char *s, char c)
{
	int		i;
	int		num;
	char	*ptr;

	num = 0;
	i = *end;
	while (s[i] == c)
		i++;
	*end = i;
	while (s[i] && !(s[i] == c))
	{
		i++;
		num++;
	}
	ptr = malloc(sizeof(char) * num + 1);
	if (ptr == NULL)
		return (NULL);
	i = *end;
	num = 0;
	while (s[i] && (!(s[i] == c)))
		ptr[num++] = s[i++];
	ptr[num] = '\0';
	*end = i;
	return (ptr);
}

int	ft_get_word_tally(const char *s, char c)
{
	int	num;
	int	words;
	int	i;

	i = 0;
	num = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && words)
		{
			num++;
			words = 0;
		}
		else if (!(s[i] == c))
			words++;
		i++;
	}
	if (words)
		num++;
	return (num);
}

char	**ft_split(const char *s, char c)
{
	int		tally;
	char	**tab;
	int		endpoint;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	endpoint = 0;
	tally = ft_get_word_tally(s, c);
	tab = malloc(sizeof(char *) * (tally + 1));
	if (tab == NULL)
		return (NULL);
	tab[tally] = NULL;
	while (i < tally)
	{
		tab[i] = ft_get_string(&endpoint, s, c);
		if (tab[i] == NULL)
		{
			ft_free_split(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

int	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return (0);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
