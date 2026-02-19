/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:31:01 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 16:13:58 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	start_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	rules_win[16];

	start_grid(grid);
	if (argc != 2)
	{
		put_error();
		return (1);
	}
	if (!convert_and_validate(argv[1], rules_win))
	{
		put_error();
		return (1);
	}
	if (solve_problem(grid, rules_win, 0))
	{
		print_grid(grid);
	}
	else
	{
		put_error();
	}
	return (0);
}
