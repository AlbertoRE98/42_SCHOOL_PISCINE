/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:29:55 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/12 08:59:11 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	ft_calc_words(char *str, char *sep)
{
	int	index;
	int	how_many;
	int	inside_word;

	index = 0;
	inside_word = 0;
	how_many = 0;
	while (str[index])
	{
		if (!is_sep(str[index], sep) && !inside_word)
		{
			how_many++;
			inside_word = 1;
		}
		else if (is_sep(str[index], sep))
		{
			inside_word = 0;
		}
		index++;
	}
	return (how_many);
}

char	*ft_word_dup(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tabla;
	int		i;
	char	*str_aux;

	str_aux = str;
	tabla = malloc ((ft_calc_words(str_aux, charset) + 1) * sizeof (char *));
	if (!tabla)
		return (NULL);
	i = 0;
	while (*str_aux)
	{
		while (*str_aux && is_sep(*str_aux, charset))
			str_aux++;
		if (*str_aux)
		{
			tabla[i] = ft_word_dup(str_aux, charset);
			i++;
			while (*str_aux && !is_sep(*str_aux, charset))
				str_aux++;
		}
	}
	tabla[i] = 0;
	return (tabla);
}
