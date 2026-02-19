/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:26:45 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 10:56:17 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	count;
	int	acum;

	acum = 1;
	count = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (count < power)
	{
		acum *= nb;
		count ++;
	}
	return (acum);
}
