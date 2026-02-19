/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:29:05 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 16:14:35 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>

void	write_char(char c);

void	print_grid(int grid[4][4]);

void	put_error(void);

int		convert_and_validate(char *str_in, int rules_win[16]);

int		count_space(char *str_in);

int		visible_from_left(int row[4]);

int		visible_from_right(int row[4]);

int		visible_from_bot(int column[4]);

int		visible_from_top(int column[4]);

int		check_con_row(int grid[4][4], int rules_win[16]);

int		check_con_col(int grid[4][4], int rules_win[16]);

int		check_win_cond(int grid[4][4], int rules_win[16]);

int		check_ok_put(int grid[4][4], int pos, int num);

int		solve_problem(int grid[4][4], int rules_win[16], int pos);

void	start_grid(int grid[4][4]);

#endif