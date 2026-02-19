/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-r <miguel-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:30:25 by miguel-r          #+#    #+#             */
/*   Updated: 2026/02/08 18:13:55 by miguel-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_space(char *str_in)
{
	int	i;
	int	space_count;

	i = 0;
	space_count = 0;
	while (str_in[i])
	{
		if (str_in[i] == ' ')
		{
			space_count++;
			if (str_in[i + 1] == ' ')
				return (-1);
		}
		i++;
	}
	return (space_count);
}

int	convert_and_validate(char *str_in, int rules_win[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str_in[i] == ' ')
		return (0);
	while (str_in[i] && count < 16)
	{
		while (str_in[i] == ' ')
			i++;
		if (str_in[i] == '\0')
			return (0);
		if (str_in[i] < '1' || str_in[i] > '4')
			return (0);
		rules_win[count] = str_in[i] - '0';
		count++;
		i++;
		if (str_in[i] && str_in[i] != ' ')
			return (0);
	}
	return (count == 16 && str_in[i] == '\0' && count_space(str_in) == 15);
}
