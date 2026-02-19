/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:28:46 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/18 16:23:52 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_dict_in_file(t_dict *dict, char *filename)
{
	int		fd;
	char	*content;
	int		result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	content = read_full_file(fd);
	close(fd);
	if (!content)
		return (0);
	result = process_buffer_reader(dict, content);
	free(content);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (0);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str)
	{
		index++;
	}
	return (index);
}
