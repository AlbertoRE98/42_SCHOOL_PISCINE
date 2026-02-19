/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:16:25 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 10:10:49 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/*
funcion para copiar la lectura al buffer
y luego usarlo
*/
void	copy_buffer(char *content, char *buffer, int to_size, int bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		content[to_size + i] = buffer[i];
		i++;
	}
}

/*
function para pinta el cuadrado
*/
void	draw_square(t_map *map, t_square sq)
{
	int	r;
	int	c;

	r = 0;
	while (r < sq.size)
	{
		c = 0;
		while (c < sq.size)
		{
			map->grid[sq.row - r][sq.col - c] = map->full;
			c++;
		}
		r++;
	}
}

/*
pintar el mapa
*/
void	print_map(t_map *map)
{
	int	index;

	if (!map || !map -> grid)
		return ;
	index = 0;
	while (index < map -> rows)
	{
		write(1, map -> grid[index], map -> cols);
		write(1, "\n", 1);
		index++;
	}
}

void	print_error(void)
{
	write(1, "map error\n", 10);
}
