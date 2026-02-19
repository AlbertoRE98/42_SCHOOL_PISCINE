/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:48:31 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 09:14:10 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*aux_str;
	char	*aux_find;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		aux_str = str;
		aux_find = to_find;
		while (*aux_str == *aux_find && *aux_find && *aux_str)
		{
			aux_str++;
			aux_find++;
			if (*aux_find == '\0')
				return (str);
		}
		str++;
	}
	return (NULL);
}
