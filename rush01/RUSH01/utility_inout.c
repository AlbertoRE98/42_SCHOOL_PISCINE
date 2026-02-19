/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_inout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:16:01 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 16:15:00 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	write_char(char c)
{
	write(1, &c, 1);
}

void	print_grid(int grid[4][4])
{
	int		row;
	int		column;
	char	number;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			number = grid[row][column] + '0';
			write_char(number);
			if (column < 3)
				write_char(' ');
			column++;
		}
		write_char('\n');
		row++;
	}
}

void	put_error(void)
{
	write (1, "Error\n", 6);
}
