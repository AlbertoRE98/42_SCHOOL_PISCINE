/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:22:28 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 10:23:48 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/*
tenemos que comprobar que los caracteres son los adecuado
primero miramos que los caracters de obstaculo y full y empty sean 
diferentes y despues comprobamos que nel grid no tengamos caracteres diferents
a los que necesitamos en el maapa 
*/
int	check_characters(t_map *map)
{
	int	index;
	int	index2;

	if (map -> empty == map -> obstacle || map -> obstacle == map -> full)
		return (0);
	if (map -> empty == map -> full)
		return (0);
	index = 0;
	while (index < map -> rows)
	{
		index2 = 0;
		while (map -> grid[index][index2])
		{
			if (map -> grid[index][index2] != map -> empty)
				if (map -> grid[index][index2] != map -> obstacle)
					return (0);
			index2++;
		}
		index++;
	}
	return (1);
}

/*
miramos los caracteres con la funcion anterior
y vamos a comprobar que todas las filas sean
correctas en cuanto a longitud
*/
int	validate_map(t_map *map)
{
	int	index;
	int	len;

	if (!map || !map->grid || map->rows <= 0)
		return (0);
	if (!check_characters(map))
		return (0);
	map->cols = ft_strlen(map->grid[0]);
	if (map->cols == 0)
		return (0);
	index = 0;
	while (index < map->rows)
	{
		len = 0;
		while (map->grid[index][len])
			len++;
		if (len != map->cols)
			return (0);
		index++;
	}
	return (1);
}
