/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:44:15 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 19:28:07 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*process_single_group(t_dict *dict, char *num_str, int i, int total)
{
	char	*group;
	char	*word;

	group = extract_group(num_str, i, total);
	if (!group || is_zero_group(group))
	{
		free(group);
		return (NULL);
	}
	word = convert_group_helper(dict, group, (total - i - 1) * 3);
	free(group);
	return (word);
}

char	*handle_zero_input(t_dict *dict, char *num_str)
{
	char	*word;

	if (num_str[0] == '0' && num_str[1] == '\0')
	{
		word = find_in_dictionary(dict, "0");
		if (word)
			return (ft_strdup(word));
		return (NULL);
	}
	return (NULL);
}

char	*process_all_groups(t_dict *dict, char *num_str, int total)
{
	char	*result;
	char	*word;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (i < total)
	{
		word = process_single_group(dict, num_str, i, total);
		if (word)
		{
			result = append_word(result, word);
			if (!result)
				return (NULL);
			free(word);
		}
		i++;
	}
	return (result);
}

char	*convert_number(t_dict *dict, char *num_str)
{
	char	*norm;
	char	*res;
	int		total;

	norm = normalize_nbr(num_str);
	if (!norm)
		return (NULL);
	if (ft_strcmp(norm, "0") == 0)
	{
		res = ft_strdup(find_in_dictionary(dict, "0"));
		free(norm);
		return (res);
	}
	total = count_groups(norm);
	res = process_all_groups(dict, norm, total);
	free(norm);
	return (res);
}
