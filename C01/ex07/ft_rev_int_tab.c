/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:23:49 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 11:23:51 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	cont;

	cont = 0;
	while (cont < size / 2)
	{
		temp = tab[cont];
		tab[cont] = tab[size - cont -1];
		tab[size - cont - 1] = temp;
		cont++;
	}
}
