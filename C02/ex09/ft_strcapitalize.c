/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:08:05 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 19:08:07 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha(char c)
{
	int	check;

	check = 0;
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
	{
		check = 1;
	}
	return (check);
}

char	*ft_strcapitalize(char *str)
{
	char	c;
	int		contador;
	int		check;

	contador = 0;
	c = str[contador];
	while (str[contador] != '\0')
	{
		check = is_alpha (str[contador]);
		if ((check == 1 && (str[contador] >= 'A' && str[contador] <= 'Z')))
		{
			str[contador] += 32;
		}
		if (str[contador] >= 'a' && str[contador] <= 'z')
		{
			if ((contador == 0 || is_alpha(str[contador - 1]) == 0))
			{
				str[contador] -= 32;
			}
		}
		contador++;
	}
	return (str);
}
