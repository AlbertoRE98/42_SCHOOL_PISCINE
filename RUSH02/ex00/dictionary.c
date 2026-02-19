/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:47:34 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 18:59:40 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	init_dict(t_dict *dict)
{
	dict -> entries = NULL;
	dict -> count = 0;
	dict -> capacity = 0;
}

int	expand_dictionary(t_dict *dict)
{
	t_entry	*new_entries;
	int		index;

	if (dict -> capacity == 0)
		dict -> capacity = STARTER_CAPACITY;
	else
		dict -> capacity *= 2;
	new_entries = malloc(sizeof(t_entry) * dict -> capacity);
	if (!new_entries)
		return (0);
	index = 0;
	while (index < dict -> count)
	{
		new_entries[index] = dict -> entries[index];
		index++;
	}
	free(dict -> entries);
	dict -> entries = new_entries;
	return (1);
}

void	free_memory_dict(t_dict *dict)
{
	int	index;

	if (!dict -> entries)
		return ;
	index = 0;
	while (index < dict -> count)
	{
		if (dict -> entries[index].number)
			free(dict -> entries[index].number);
		if (dict -> entries[index].word)
			free(dict -> entries[index].word);
		index++;
	}
	free(dict -> entries);
	dict -> entries = NULL;
	dict -> count = 0;
	dict -> capacity = 0;
}

int	add_dict_entry_for_number(t_dict *dic, char *n, char *wd)
{
	char	*fixed_nbr;

	if (dic -> count >= dic -> capacity && !expand_dictionary(dic))
		return (0);
	fixed_nbr = normalize_nbr(n);
	if (!fixed_nbr)
		return (0);
	dic -> entries[dic -> count].number = fixed_nbr;
	dic -> entries[dic -> count].word = ft_strdup(wd);
	if (!dic -> entries[dic -> count].word)
	{
		free(fixed_nbr);
		return (0);
	}
	dic -> count++;
	return (1);
}

char	*find_in_dictionary(t_dict *dict, char *n)
{
	char	*fixed_str;
	int		index;
	char	*result;

	fixed_str = normalize_nbr(n);
	if (!fixed_str)
		return (NULL);
	result = NULL;
	index = 0;
	while (index < dict -> count)
	{
		if (ft_strcmp(dict -> entries[index].number, fixed_str) == 0)
		{
			result = dict -> entries[index].word;
			break ;
		}
		index++;
	}
	free (fixed_str);
	return (result);
}
