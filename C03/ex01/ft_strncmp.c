/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:21:30 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/03 19:21:40 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	cont;

	cont = 0;
	while (cont < n && *s1 && *s2 && (*s1 == *s2))
	{
		cont++;
		s1++;
		s2++;
	}
	if (cont == n)
		return (0);
	return ((*(const unsigned char *)s1 - *(const unsigned char *)s2));
}

/*
int main(void)
{
	// Test 1: Equal strings, n == length
	printf("Test 1: %d | expected: 0\n", ft_strncmp("hello", "hello", 5));

	// Test 2: Equal strings, n < length
	printf("Test 2: %d | expected: 0\n", ft_strncmp("hello", "hello", 3));

	// Test 3: Equal strings, n > length
	printf("Test 3: %d | expected: 0\n", ft_strncmp("hello", "hello", 10));
	
	return (0);
}
*/