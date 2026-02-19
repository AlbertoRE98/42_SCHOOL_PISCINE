/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:11:13 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 19:29:17 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	is_valid_number(char *str)
{
	char	*str_aux;

	str_aux = str;
	if (!str_aux || !*str_aux)
		return (0);
	while (*str_aux)
	{
		if (!ft_is_digit(*str_aux))
			return (0);
		str_aux++;
	}
	return (1);
}

void	ft_put_str(char *str, int ft)
{
	write(ft, str, ft_strlen(str));
}

char	*ft_strdup(char *str)
{
	char	*duplic;
	int		len;
	int		index;

	len = ft_strlen(str);
	duplic = malloc(sizeof(char) * (len + 1));
	if (!duplic)
		return (NULL);
	index = 0;
	while (index < len)
	{
		duplic[index] = str[index];
		index++;
	}
	duplic[index] = '\0';
	return (duplic);
}
