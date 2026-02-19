/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:33:22 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 12:34:27 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		index;

	index = 0;
	while (src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_str_cat(char *dest, char *src)
{
	int	index;
	int	index2;

	index = 0;
	while (dest[index])
		index++;
	index2 = 0;
	while (src[index2])
	{
		dest[index + index2] = src[index2];
		index2++;
	}
	dest[index + index2] = '\0';
	return (dest);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_str_cat(res, s2);
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	index;

	index = 0;
	while (index < n && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
