/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:28:06 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 09:01:09 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		cont;
	char				*or_dest;

	or_dest = dest;
	cont = 0;
	while (*dest)
	{
		dest++;
	}
	while (*src && cont < nb)
	{
		*dest = *src;
		src++;
		dest++;
		cont++;
	}
	*dest = '\0';
	return (or_dest);
}
