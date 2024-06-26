/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:54:09 by jewu              #+#    #+#             */
/*   Updated: 2024/04/12 16:01:25 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = ft_calloc_gnl((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1),
			sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup_gnl(char *s)
{
	char	*result;
	int		j;

	j = 0;
	result = ft_calloc_gnl((ft_strlen_gnl(s) + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (s[j] != '\0')
	{
		result[j] = s[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

void	*ft_calloc_gnl(int nmemb, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
