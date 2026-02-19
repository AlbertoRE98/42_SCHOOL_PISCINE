/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliares.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:51:49 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/16 12:59:39 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (*str)
	{
		index++;
		str++;
	}
	return (index);
}

char	*ft_strdup(char *str)
{
	char	*duplicate;
	int		index;
	int		tam;

	tam = ft_strlen(str);
	index = 0;
	duplicate = malloc(sizeof(char) * (tam + 1));
	if (!duplicate)
		return (NULL);
	while (index < tam)
	{
		duplicate[index] = str[index];
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

int	ft_atoi(char *str)
{
	int	res;
	int	index;

	res = 0;
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - '0');
		index++;
	}
	return (res);
}

void	free_map(t_map *map)
{
	int	index;

	if (!map)
		return ;
	if (map -> grid)
	{
		index = 0;
		while (index < map -> rows)
		{
			if (map -> grid[index])
				free (map -> grid[index]);
			index++;
		}
		free(map -> grid);
	}
	free(map);
}
