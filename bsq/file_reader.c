/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:38:31 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 10:03:28 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
esta función toma la cadena existente y crea una nueva más grande
y copia el contenido anterior por si acaso necesitamos mas memoria
*/
char	*ft_realloc(char *old_ptr, int old_size, int new_size)
{
	char	*new_ptr;
	int		i;

	new_ptr = malloc(sizeof(char) * (new_size + 1));
	if (!new_ptr)
		return (NULL);
	i = 0;
	if (old_ptr)
	{
		while (i < old_size)
		{
			new_ptr[i] = old_ptr[i];
			i++;
		}
		free(old_ptr);
	}
	return (new_ptr);
}

/*
lee el archivo desde fd (file descriptor q se usa en read)
ttotal_size lleva la cuenta de cuántos caracteres hemos acumulado.
*/
char	*read_file(int fd)
{
	char	buffer[4096];
	char	*content;
	int		bytes_read;
	int		total_size;

	total_size = 0;
	content = NULL;
	bytes_read = read(fd, buffer, 4096);
	while (bytes_read > 0)
	{
		content = ft_realloc(content, total_size, total_size + bytes_read);
		if (!content)
			return (NULL);
		copy_buffer(content, buffer, total_size, bytes_read);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, 4096);
	}
	if (content)
		content[total_size] = '\0';
	return (content);
}
