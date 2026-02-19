/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:58:23 by aramos-e          #+#    #+#             */
/*   Updated: 2026/01/30 08:58:26 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_character(int *numbers, int n)
{
	char	c_translated;
	int		counter;

	counter = 0;
	while (counter < n)
	{
		c_translated = numbers[counter] + '0';
		write (1, &c_translated, 1);
		counter++;
	}
}

void	ft_create_combn(int n, int *numbers, int index, int actual_number)
{
	if (index == n)
	{
		write_character (numbers, n);
		if (numbers[0] < 10 - n)
			write(1, ", ", 1);
	}
	else
	{
		while (actual_number <= 9)
		{
			numbers[index] = actual_number;
			ft_create_combn (n, numbers, index + 1, actual_number + 1);
			actual_number++;
		}
	}
}

void	ft_print_combn(int n)
{
	int		numbers [10];

	if (n > 0 && n < 10)
		ft_create_combn (n, numbers, 0, 0);
}
/*
int	main(void)
{
	ft_print_combn(2);
	return (0);
}
*/