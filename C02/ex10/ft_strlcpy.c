/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:44:53 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/02 08:44:55 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cont;
	unsigned int	src_size;

	cont = 0;
	src_size = 0;
	while (src[cont] != '\0')
	{
		src_size++;
		cont++;
	}
	if (size == 0)
		return (src_size);
	cont = 0;
	while (src[cont] != '\0' && cont < size - 1)
	{
		dest[cont] = src[cont];
		cont++;
	}
	dest[cont] = '\0';
	return (src_size);
}
