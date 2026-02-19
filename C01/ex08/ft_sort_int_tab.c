/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:58:38 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 11:58:40 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	cont;
	int	cont2;

	cont = 0;
	cont2 = 0;
	while (cont < size - 1)
	{
		cont2 = 0;
		while (cont2 < size - cont -1)
		{
			if (tab[cont2] > tab[cont2 + 1])
			{
				temp = tab[cont2];
				tab[cont2] = tab[cont2 + 1];
				tab[cont2 + 1] = temp;
			}
			cont2++;
		}
		cont++;
	}
}
