/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:33:21 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/05 09:47:56 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char*origin)
{
	char	*str_dest;

	str_dest = dest;
	while (*dest)
	{
		dest++;
	}
	while (*origin)
	{
		*dest = *origin;
		dest++;
		origin++;
	}
	*dest = '\0';
	return (str_dest);
}

int	ft_strlen(char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

int	ft_strlen_ptrptr(char **strs, int size_strs)
{
	int	cont_loop_1;
	int	res;

	res = 0;
	cont_loop_1 = 0;
	while (cont_loop_1 < size_strs)
	{
		res += ft_strlen(strs [cont_loop_1]);
		cont_loop_1++;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res_cat;
	int		tam_tot_alloc;
	int		cont;

	if (size == 0)
	{
		res_cat = malloc (1 * sizeof (char));
		res_cat [0] = '\0';
		return (res_cat);
	}
	tam_tot_alloc = ft_strlen(sep) * (size - 1);
	tam_tot_alloc += ft_strlen_ptrptr(strs, size) + 1;
	res_cat = malloc (tam_tot_alloc * sizeof (char));
	if (!res_cat)
		return (NULL);
	res_cat[0] = '\0';
	cont = 0;
	while (cont < size)
	{
		ft_strcat(res_cat, strs[cont]);
		if (cont < size -1)
			ft_strcat(res_cat, sep);
		cont++;
	}
	return (res_cat);
}
/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char*origin)
{
	int		count;
	char	*str_dest;

	str_dest = dest;
	while (*dest)
	{
		dest++;
	}
	while (*origin)
	{
		*dest = *origin;
		dest++;
		origin++;
	}
	*dest = '\0';
	return (str_dest);
}

int	ft_strlen(char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

int	ft_strlen_ptrptr(char **strs, int size_strs)
{
	int	cont_loop_1;
	int	res;

	res = 0;
	cont_loop_1 = 0;
	while (cont_loop_1 < size_strs)
	{
		res += ft_strlen(strs [cont_loop_1]);
		cont_loop_1++;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res_cat;
	int		tam_tot_alloc;
	int		cont;

	if (size == 0)
	{
		res_cat = malloc (1 * sizeof (char));
		res_cat [0] = '\0';
		return (res_cat);
	}
	tam_tot_alloc = ft_strlen(sep) * (size -1);
	tam_tot_alloc += ft_strlen_ptrptr(strs, size) + 1;
	res_cat = malloc (tam_tot_alloc * sizeof (char));
	if (!res_cat)
		return (NULL);
	res_cat[0] = '\0';
	cont = 0;
	while (cont < size)
	{
		ft_strcat(res_cat, strs[cont]);
		if (cont < size -1)
			ft_strcat(res_cat, sep);
		cont++;
	}
	return (res_cat);
}
	
int main(void)
{
    printf("=== PRUEBAS ft_strjoin ===\n\n");
    
    // Test 1: Caso Normal Básico
    printf("=== Test 1: Caso Normal ===\n");
    char *strs1[] = {"Hello", "world", "from", "C"};
    char *result1 = ft_strjoin(4, strs1, " ");
    printf("Input: 4 strings, sep=' '\n");
    printf("Result: '%s'\n", result1);
    printf("Expected: 'Hello world from C'\n");
    if (result1 && strcmp(result1, "Hello world from C") == 0)
        printf("✓ PASS\n\n");
    else
        printf("✗ FAIL\n\n");
    free(result1);
    
    // Test 2: Strings Vacíos y Sep Complejo
    printf("=== Test 2: Strings Vacíos ===\n");
    char *strs2[] = {"", "test", "", "end"};
    char *result2 = ft_strjoin(4, strs2, "---");
    printf("Input: [\"\", \"test\", \"\", \"end\"], sep='---'\n");
    printf("Result: '%s'\n", result2);
    printf("Expected: '---test------end'\n");
    if (result2 && strcmp(result2, "---test------end") == 0)
        printf("✓ PASS\n\n");
    else
        printf("✗ FAIL\n\n");
    free(result2);
    
    printf("=== Test 3: Un Solo String ===\n");
    char *strs3[] = {"OnlyOneString"};
    char *result3 = ft_strjoin(1, strs3, "ShouldNotAppear");
    printf("Input: 1 string, sep='ShouldNotAppear'\n");
    printf("Result: '%s'\n", result3);
    printf("Expected: 'OnlyOneString'\n");
    if (result3 && strcmp(result3, "OnlyOneString") == 0)
        printf("✓ PASS\n\n");
    else
        printf("✗ FAIL\n\n");
    free(result3);
    
    printf("=== Test 4: size = 0 ===\n");
    char *result4 = ft_strjoin(0, NULL, "anything");
    printf("Input: size=0\n");
    printf("Result: '%s'\n", result4 ? result4 : "NULL");
    printf("Expected: '' (string vacío)\n");
    if (result4 && strcmp(result4, "") == 0)
        printf("✓ PASS\n\n");
    else
        printf("✗ FAIL\n\n");
    if (result4) free(result4);
    
    return (0);
}
*/