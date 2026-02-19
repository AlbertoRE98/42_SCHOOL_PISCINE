/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:05:18 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 19:05:20 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int		contador;
	char	c;

	contador = 0;
	c = str[contador];
	while (c != '\0')
	{
		if (c >= 'A' && c <= 'Z')
			str[contador] += 32;
		contador++;
		c = str[contador];
	}
	return (str);
}
