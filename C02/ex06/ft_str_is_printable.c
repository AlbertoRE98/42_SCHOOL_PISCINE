/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:50:11 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 18:50:13 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	char	c;
	int		value;

	value = 1;
	c = *str;
	while ((c != '\0') && (value != 0))
	{
		if (!(c >= 32 && c <= 126))
		{
			value = 0;
		}
		str++;
		c = *str;
	}
	return (value);
}
