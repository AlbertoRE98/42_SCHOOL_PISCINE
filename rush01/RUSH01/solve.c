/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:15:34 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 16:14:45 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve_problem(int grid[4][4], int rules_win[16], int pos)
{
	int	row_now;
	int	col_now;
	int	num;

	if (pos == 16)
		return (check_win_cond(grid, rules_win));
	row_now = pos / 4;
	col_now = pos % 4;
	if (grid[row_now][col_now] != 0)
		return (solve_problem(grid, rules_win, pos + 1));
	num = 1;
	while (num <= 4)
	{
		if (check_ok_put (grid, pos, num))
		{
			grid[row_now][col_now] = num;
			if (solve_problem(grid, rules_win, pos + 1))
				return (1);
			grid[row_now][col_now] = 0;
		}
		num++;
	}
	return (0);
}
