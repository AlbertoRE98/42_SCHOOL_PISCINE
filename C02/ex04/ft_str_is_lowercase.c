/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:44:50 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 18:44:51 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	char	c;
	int		value;

	value = 1;
	c = *str;
	while ((c != '\0') && (value != 0))
	{
		if (!(c >= 'a' && c <= 'z'))
		{
			value = 0;
		}
		str++;
		c = *str;
	}
	return (value);
}
