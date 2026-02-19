/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:54:30 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 18:54:32 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int		contador;
	char	c;

	contador = 0;
	c = str[contador];
	while (c != '\0')
	{
		if (c >= 'a' && c <= 'z')
			str[contador] -= 32;
		contador++;
		c = str[contador];
	}
	return (str);
}
