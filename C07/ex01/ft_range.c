/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:11:38 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/05 08:36:58 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	tam_arr;
	int	*ptr_array_nb;
	int	count;

	if (min >= max)
		return (NULL);
	tam_arr = max - min;
	ptr_array_nb = malloc (tam_arr * sizeof(int));
	if (!ptr_array_nb)
		return (NULL);
	count = 0;
	while (count < tam_arr)
	{
		ptr_array_nb[count] = min + count;
		count++;
	}
	return (ptr_array_nb);
}
