/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:40:09 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 18:40:11 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	char	c;
	int		value;

	value = 1;
	c = *str;
	while ((c != '\0') && (value != 0))
	{
		if (!(c >= '0' && c <= '9'))
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
