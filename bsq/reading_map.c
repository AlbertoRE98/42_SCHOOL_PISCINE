/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:09:16 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 17:35:50 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/*
la primera linea debe ser manejada de forma diferente
a lo demas, debido a que es una estructura especial.
leemos hasta el \n, comprobamos el tamaño, e inicializamos
nuestra estructura
*/
int	get_map_params(t_map *map, char *str)
{
	int		len;
	char	saved_char;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (len < 4)
		return (-1);
	map->full = str[len - 1];
	map->obstacle = str[len - 2];
	map->empty = str[len - 3];
	saved_char = str[len - 3];
	str[len - 3] = '\0';
	map->rows = ft_atoi(str);
	str[len - 3] = saved_char;
	if (map->rows <= 0)
		return (-1);
	return (len + 1);
}

int	get_map_cols(char *str)
{
	int	cols;

	cols = 0;
	while (str[cols] && str[cols] != '\n')
		cols++;
	return (cols);
}

/*
reserva memoria exacta para las filas y columnas.
si falla un malloc, libera todo lo anterior 
*/
int	allocate_map_memory(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->grid[i])
		{
			while (--i >= 0)
				free(map->grid[i]);
			free(map->grid);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
copia el contenido del string a la matriz
valida sobre la marcha que las líneas tengan la misma longitud.
*/
int	fill_grid_data(t_map *map, char *str)
{
	int	r;
	int	c;
	int	i;

	r = 0;
	i = 0;
	while (r < map->rows && str[i])
	{
		c = 0;
		while (str[i] && str[i] != '\n')
		{
			if (c >= map->cols)
				return (0);
			map->grid[r][c] = str[i];
			c++;
			i++;
		}
		if (c != map->cols)
			return (0);
		map->grid[r][c] = '\0';
		r++;
		if (str[i] == '\n')
			i++;
	}
	return (r == map->rows);
}

/*
procesa todo para meterlo en el mapa
*/
t_map	*process_map_string(char *file_content)
{
	t_map	*map;
	int		start_idx;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	start_idx = get_map_params(map, file_content);
	if (start_idx == -1)
	{
		free(map);
		return (NULL);
	}
	map->cols = get_map_cols(file_content + start_idx);
	if (map->cols == 0 || !allocate_map_memory(map))
	{
		free(map);
		return (NULL);
	}
	if (!fill_grid_data(map, file_content + start_idx))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
