/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:53:48 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/05 08:37:00 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		str_len;
	char	*src_dup;
	char	*dup_aux;
	char	*src_aux;

	str_len = 0;
	while (src[str_len])
		str_len++;
	src_dup = malloc ((str_len + 1) * sizeof(char));
	dup_aux = src_dup;
	src_aux = src;
	if (src_dup == NULL)
		return (NULL);
	while (*src_aux)
	{
		*dup_aux = *src_aux;
		dup_aux++;
		src_aux++;
	}
	*dup_aux = '\0';
	return (src_dup);
}
