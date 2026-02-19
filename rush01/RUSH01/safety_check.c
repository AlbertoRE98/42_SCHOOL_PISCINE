/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:26:16 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 16:14:40 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_placement_not_rep(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_ok_put(int grid[4][4], int pos, int num)
{
	int	r;
	int	c;

	r = pos / 4;
	c = pos % 4;
	return (is_valid_placement_not_rep(grid, r, c, num));
}
