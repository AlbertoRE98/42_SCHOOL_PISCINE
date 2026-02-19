/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:10:35 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/02 17:10:39 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	if (str[counter] == '\0')
		return (counter);
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

/*
int main(void)
{
char * prueba;
int a;

prueba = "enseñame esto";

a = ft_strlen(prueba);
printf ("%d\n",a);
return (0);
}
*/