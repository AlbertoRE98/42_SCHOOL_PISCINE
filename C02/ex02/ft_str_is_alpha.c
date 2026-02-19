/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:20:24 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 14:20:26 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	char	c;
	int		value;

	value = 1;
	c = *str;
	while ((c != '\0') && (value != 0))
	{
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		{
			value = 0;
		}
		str++;
		c = *str;
	}
	return (value);
}

/*
int main (void)
{
	char *hola = "";
	int a=ft_str_is_alpha(hola);
	char p= a +'0';

	write(1,&p,1);

	return (0);
}
	*/
