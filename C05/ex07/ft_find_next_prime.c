/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:33:36 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/09 13:14:06 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	aux;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	aux = 3;
	while (aux != nb)
	{
		if (nb % aux == 0)
			return (0);
		aux += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	if (nb < 2)
		return (2);
	if (nb == 2)
		return (2);
	if (nb % 2 == 1)
		nb += 2;
	else
		nb++;
	while (ft_is_prime(nb) != 1)
	{
		nb += 2;
	}
	return (nb);
}
