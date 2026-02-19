/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:59:26 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 16:15:09 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	visible_from_left(int row[4])
{
	int	i;
	int	max_height;
	int	how_many_vis;

	i = 0;
	max_height = 0;
	how_many_vis = 0;
	while (i < 4)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			how_many_vis++;
		}
		i++;
	}
	return (how_many_vis);
}

int	visible_from_right(int row[4])
{
	int	i;
	int	max_height;
	int	how_many_vis;

	i = 3;
	max_height = 0;
	how_many_vis = 0;
	while (i >= 0)
	{
		if (row[i] > max_height)
		{
			max_height = row[i];
			how_many_vis++;
		}
		i--;
	}
	return (how_many_vis);
}

int	visible_from_top(int column[4])
{
	int	i;
	int	max_height;
	int	how_many_vis;

	i = 0;
	max_height = 0;
	how_many_vis = 0;
	while (i < 4)
	{
		if (column[i] > max_height)
		{
			max_height = column [i];
			how_many_vis++;
		}
		i++;
	}
	return (how_many_vis);
}

int	visible_from_bot(int column[4])
{
	int	i;
	int	max_height;
	int	how_many_vis;

	i = 3;
	max_height = 0;
	how_many_vis = 0;
	while (i >= 0)
	{
		if (column[i] > max_height)
		{
			max_height = column [i];
			how_many_vis++;
		}
		i--;
	}
	return (how_many_vis);
}
