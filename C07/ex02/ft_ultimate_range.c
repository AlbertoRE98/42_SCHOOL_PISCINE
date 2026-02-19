/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:23:05 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/09 12:09:35 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	counter;
	int	tam;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tam = max - min;
	*range = malloc (tam * sizeof (int));
	if (!*range)
		return (-1);
	counter = 0;
	while (counter < tam)
	{
		(*range)[counter] = min + counter;
		counter++;
	}
	return (tam);
}
