/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:48:11 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/02 17:48:27 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	its_negative;
	int	counter;
	int	res;

	res = 0;
	counter = 0;
	its_negative = 1;
	while (str[counter] == ' '
		|| (str[counter] >= '\t' && str[counter] <= '\r'))
	{
		counter++;
	}
	while (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			its_negative *= -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		res = (res * 10) + (str[counter] - '0');
		counter++;
	}
	return (res * its_negative);
}

/*
#include <stdio.h>
#include <stdlib.h> // Para comparar con el atoi original si quieres

int	main(void)
{

	char *s1 = "   ---+--+1234ab567";
	printf("Test 1 
	(Enunciado):\nEntrada: 
	\"%s\"\nResultado: %d\n\n", s1, ft_atoi(s1));


	char *s2 = "\t\n\v\f\r 42";
	printf("Test 2 
	(Espacios de control):\nEntrada
	: \"\\t\\n\\v\\f\\r 42\"\nResultado: 
	%d\n\n", ft_atoi(s2));

	
	char *s3 = "++--++42";
	printf("Test 3 (Pares de menos)
	:\nEntrada: \"%s\"\nResultado: %d\n\n",
	 s3, ft_atoi(s3));


	
	char *s6 = "  -123";
	printf("Test 6 (Negativo simple):\nEntrada:
	 \"%s\"\nResultado: %d\n\n", s6, ft_atoi(s6));

	return (0);
}
	*/
