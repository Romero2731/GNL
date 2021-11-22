/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disle <disle@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:19:40 by disle             #+#    #+#             */
/*   Updated: 2021/11/22 17:37:43 by disle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*big;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	big = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!big)
		return (NULL);
	while (s1[i] != '\0')
	{
		big[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		big[i++] = s2[j++];
	big[i] = '\0';
	free(s1);
	return (big);
}

int	ft_strlen_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (i + 1);
}
