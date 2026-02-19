/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:30:54 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 10:22:28 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_min_val(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	free_int_tab(int **arr, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	process_cell(t_map *map, int **arr, int *pos, t_square *best)
{
	int	r;
	int	c;

	r = pos[0];
	c = pos[1];
	if (map->grid[r][c] == map->obstacle)
		arr[r][c] = 0;
	else if (r == 0 || c == 0)
		arr[r][c] = 1;
	else
		arr[r][c] = get_min_val(arr[r - 1][c], arr[r][c - 1],
				arr[r - 1][c - 1]) + 1;
	if (arr[r][c] > best->size)
	{
		best->size = arr[r][c];
		best->row = r;
		best->col = c;
	}
}

void	solve_bsq(t_map *map)
{
	int			**arr;
	int			pos[2];
	t_square	best;

	best.size = 0;
	arr = malloc(sizeof(int *) * map->rows);
	if (!arr)
		return ;
	pos[0] = -1;
	while (++pos[0] < map->rows)
	{
		arr[pos[0]] = malloc(sizeof(int) * map->cols);
		if (!arr[pos[0]])
		{
			free_int_tab(arr, pos[0]);
			return ;
		}
		pos[1] = -1;
		while (++pos[1] < map->cols)
			process_cell(map, arr, pos, &best);
	}
	draw_square(map, best);
	free_int_tab(arr, map->rows);
}
