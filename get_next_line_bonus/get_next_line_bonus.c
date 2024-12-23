/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:50 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/22 19:01:55 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*last_line(char *storage, char *buffer)
{
	char	*line;

	if (!storage)
		return (free(buffer), NULL);
	if (!storage[0])
	{
		free(storage);
		storage = NULL;
		return (free(buffer), NULL);
	}
	line = ft_substr(storage, 0, ft_strlen(storage));
	free(storage);
	return (free(buffer), line);
}

char	*read_and_store(int fd, char *storage)
{
	int		bytesread;
	char	*buffer;
	char	*aux;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(storage, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(buffer), free(storage), NULL);
		if (bytesread == 0)
			return (last_line(storage, buffer));
		buffer[bytesread] = '\0';
		aux = storage;
		storage = ft_strjoin(aux, buffer);
		free(aux);
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*find_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

char	*new_storage(char *storage)
{
	int		i;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i);
	free(storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	storage[fd] = read_and_store(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = find_line(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = new_storage(storage[fd]);
	return (line);
}

/*#include <stdio.h>

int	main(void)
{
	int fd;
	int fd1;
	int fd2;
	char *line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text2.txt", O_RDONLY);
	fd2 = open("text3.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}*/