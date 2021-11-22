/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disle <disle@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:20:04 by disle             #+#    #+#             */
/*   Updated: 2021/11/22 21:05:24 by disle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_reminder(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (str[i] != '\0')
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!*str)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen_n(str) + 1));
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(char	*str, int fd)
{
	int			byte_read;
	char		buf[BUFFER_SIZE + 1];

	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(str, '\n'))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buf[byte_read] = '\0';
		if (!str)
		{
			str = malloc(1);
			if (!str)
				return (NULL);
			str[0] = '\0';
		}
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_line_reminder(str);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
