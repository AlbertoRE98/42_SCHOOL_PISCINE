/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:14:58 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 11:34:16 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	possible_number;

	possible_number = 1;
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (nb);
	while (possible_number * possible_number <= nb)
	{
		if (possible_number * possible_number == nb)
			return (possible_number);
		possible_number++;
	}
	return (0);
}
