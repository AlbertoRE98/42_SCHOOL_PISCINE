/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:48:10 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 09:03:54 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("--- STARTING TESTS ---\n\n");

     Identical strings
    run_test("Hello", "Hello");

    // Test 2: Different characters (s1 > s2)
    run_test("abcde", "abccde");

    // Test 3: Different lengths (s1 < s2)
    run_test("Apple", "ApplePie");

    // Test 4: Empty string
    run_test("", "Something");

    // Test 5: First character difference
    run_test("Z", "A");

    return (0);
}
*/