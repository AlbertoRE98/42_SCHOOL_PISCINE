/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:11:58 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 12:45:53 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*normalize_nbr(char *str_nbr)
{
	char	*str_fixed;
	char	*aux_str;
	int		i;

	aux_str = str_nbr;
	while (*aux_str == '0' && *(aux_str + 1))
		aux_str++;
	str_fixed = malloc(ft_strlen(aux_str) + 1);
	if (!str_fixed)
		return (NULL);
	i = 0;
	while (aux_str[i])
	{
		str_fixed[i] = aux_str[i];
		i++;
	}
	str_fixed[i] = '\0';
	return (str_fixed);
}

char	*remove_seps(char *str)
{
	char	*end;

	while (*str && ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (str);
	end = str;
	while (*end)
		end++;
	end--;
	while (end > str && ft_isspace(*end))
		end--;
	*(end + 1) = '\0';
	return (str);
}

int	process_line(t_dict *dict, char *line)
{
	char				*com;
	char				*numbr_str;
	char				*word_str;

	com = line;
	while (*com && *com != ':')
		com++;
	if (*com != ':')
		return (0);
	*com = '\0';
	numbr_str = remove_seps(line);
	word_str = remove_seps(com + 1);
	if (!*numbr_str || !*word_str)
		return (0);
	if (!add_dict_entry_for_number(dict, numbr_str, word_str))
		return (0);
	return (1);
}

int	process_single_line(t_dict *dict, char *start, char *newline)
{
	if (newline)
		*newline = '\0';
	if (*start && !process_line(dict, start))
		return (0);
	return (1);
}

char	*find_and_process_line(t_dict *dict, char *start, int *ok)
{
	char	*newline;

	newline = ft_strchr(start, '\n');
	if (newline)
	{
		if (!process_single_line(dict, start, newline))
			*ok = 0;
		return (newline + 1);
	}
	if (*start && !process_line(dict, start))
		*ok = 0;
	return (NULL);
}
