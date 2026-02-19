/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:53:25 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 10:56:20 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	counter;

	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		return (1);
	}
	factorial = 1;
	counter = 1;
	while (counter <= nb)
	{
		factorial = factorial * counter;
		counter ++;
	}
	return (factorial);
}
