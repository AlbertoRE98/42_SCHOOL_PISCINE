/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:15:10 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 09:04:13 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	counter;

	counter = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len == size)
		return (size + src_len);
	counter = 0;
	while (counter + dest_len < size - 1 && src[counter])
	{
		dest[dest_len + counter] = src[counter];
		counter++;
	}
	dest[dest_len + counter] = '\0';
	return (dest_len + src_len);
}
