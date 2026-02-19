/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:09:55 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 12:45:14 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*find_newline(char *str)
{
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		return (str);
	return (NULL);
}

char	*join_buffers(char *old, char *new, int old_len, int new_len)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(old_len + new_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < old_len)
	{
		result[i] = old[i];
		i++;
	}
	j = 0;
	while (j < new_len)
	{
		result[i + j] = new[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

int	process_buffer_reader(t_dict *dict, char *buffer)
{
	char	*start;
	int		ok;

	start = buffer;
	ok = 1;
	while (start && *start)
	{
		start = find_and_process_line(dict, start, &ok);
		if (!start)
			break ;
	}
	return (ok);
}

char	*process_read_block(char *content, char *temp, int total, int bytes)
{
	char	*new_content;

	temp[bytes] = '\0';
	new_content = join_buffers(content, temp, total, bytes);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	free(content);
	return (new_content);
}

char	*read_full_file(int fd)
{
	char	temp[BUFFER_SIZE];
	char	*content;
	int		bytes;
	int		total;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	total = 0;
	while (1)
	{
		bytes = read(fd, temp, BUFFER_SIZE - 1);
		if (bytes <= 0)
			break ;
		content = process_read_block(content, temp, total, bytes);
		if (!content)
			return (NULL);
		total += bytes;
	}
	return (content);
}
