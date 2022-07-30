/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:12:44 by florianma         #+#    #+#             */
/*   Updated: 2021/09/02 18:26:39 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	ft_count(char const *str, char c)
{
	int	i;
	int	compteur;

	i = 0;
	compteur = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			compteur++;
		while (str[i] != c && str[i])
			i++;
	}
	return (compteur);
}

char	**ft_allocate(char const *s, char c, char **dest, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
		{
			j++;
			k++;
		}
		dest[i] = (char *)malloc((j + 1) * sizeof(char));
		if (dest[i] == NULL)
			return (NULL);
		i++;
		j = 0;
	}
	dest[i] = 0;
	return (dest);
}

char	**fill_it_up(char const *s, char c, char **dest, int size)
{	
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
		{
			dest[i][j] = s[k];
			j++;
			k++;
		}
		dest[i][j] = '\0';
		j = 0;
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c, int *final_size)
{
	char	**dest;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count(s, c);
	dest = (char **)malloc((size + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	ft_allocate(s, c, dest, size);
	fill_it_up(s, c, dest, size);
	*final_size = size;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0' && s1 && s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0' && s2[j] && s2)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
