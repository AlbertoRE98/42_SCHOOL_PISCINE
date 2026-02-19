/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_conditions_win.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:27:15 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 18:18:43 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_con_row(int grid[4][4], int rules_win[16])
{
	int	i;
	int	row[4];

	i = 0;
	while (i < 4)
	{
		row[0] = grid[i][0];
		row[1] = grid[i][1];
		row[2] = grid[i][2];
		row[3] = grid[i][3];
		if (visible_from_left(row) != rules_win[i + 8])
			return (0);
		if (visible_from_right(row) != rules_win[i + 12])
			return (0);
		i++;
	}
	return (1);
}

int	check_con_col(int grid[4][4], int rules_win[16])
{
	int	i;
	int	col[4];

	i = 0;
	while (i < 4)
	{
		col[0] = grid[0][i];
		col[1] = grid[1][i];
		col[2] = grid[2][i];
		col[3] = grid[3][i];
		if (visible_from_top(col) != rules_win[i])
			return (0);
		if (visible_from_bot(col) != rules_win[i + 4])
			return (0);
		i++;
	}
	return (1);
}

int	check_win_cond(int grid[4][4], int rules_win[16])
{
	if (!check_con_col(grid, rules_win))
		return (0);
	if (!check_con_row(grid, rules_win))
		return (0);
	return (1);
}
