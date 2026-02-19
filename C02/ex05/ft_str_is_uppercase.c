/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:47:50 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 18:47:52 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	char	c;
	int		value;

	value = 1;
	c = *str;
	while ((c != '\0') && (value != 0))
	{
		if (!(c >= 'A' && c <= 'Z'))
		{
			value = 0;
		}
		str++;
		c = *str;
	}
	return (value);
}
