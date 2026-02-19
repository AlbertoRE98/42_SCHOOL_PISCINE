/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:46:20 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/10 16:19:28 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_safe(int board[10], int row, int column)
{
	int	col_old;
	int	diff_row;
	int	diff_column;

	col_old = 0;
	while (col_old < column)
	{
		diff_row = board[col_old] - row;
		diff_column = col_old - column;
		if (board[col_old] == row)
			return (0);
		if (diff_row < 0)
			diff_row *= -1;
		if (diff_column < 0)
			diff_column *= -1;
		if (diff_column == diff_row)
			return (0);
		col_old++;
	}
	return (1);
}

void	print_sols(int board[10])
{
	char	digit_to_print;
	int		count;

	count = 0;
	while (count < 10)
	{
		digit_to_print = board[count] + '0';
		write (1, &digit_to_print, 1);
		count++;
	}
	write (1, "\n", 1);
}

void	solve(int board[10], int column, int *count)
{
	int	row;

	if (column == 10)
	{
		print_sols(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe (board, row, column))
		{
			board[column] = row;
			solve(board, column + 1, count);
		}
		row ++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	solve(board, 0, &count);
	return (count);
}
