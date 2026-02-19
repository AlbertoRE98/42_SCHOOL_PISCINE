/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:12:34 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 19:27:04 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*append_word(char *pre_word, char *word)
{
	char	*tmp;
	char	*res;

	if (!pre_word || !word)
	{
		if (pre_word)
			free(pre_word);
		return (NULL);
	}
	tmp = ft_str_join(pre_word, " ");
	if (!tmp)
	{
		free(pre_word);
		return (NULL);
	}
	res = ft_str_join(tmp, word);
	free(tmp);
	free(pre_word);
	return (res);
}

char	*handle_two_digit_number(t_dict *dict, char *group)
{
	char	temp[3];
	char	*result;
	char	*tens;
	char	*unit_word;

	temp[0] = group[0];
	temp[1] = '0';
	temp[2] = '\0';
	tens = find_in_dictionary(dict, temp);
	if (!tens)
		return (NULL);
	result = ft_strdup(tens);
	if (!result)
		return (NULL);
	if (group[1] != '0')
	{
		temp[0] = group[1];
		temp[1] = '\0';
		unit_word = find_in_dictionary(dict, temp);
		if (unit_word)
			result = append_word(result, unit_word);
	}
	return (result);
}

char	*convert_under_100(t_dict *dict, char *group)
{
	char	*word;

	word = find_in_dictionary(dict, group);
	if (word)
		return (ft_strdup(word));
	if (ft_strlen(group) == 2)
		return (handle_two_digit_number(dict, group));
	return (NULL);
}

char	*process_hundred_digit(t_dict *dict, char digit)
{
	char	temp[2];
	char	*result;
	char	*hundred;

	temp[0] = digit;
	temp[1] = '\0';
	result = ft_strdup(find_in_dictionary(dict, temp));
	if (!result)
		return (NULL);
	hundred = find_in_dictionary(dict, "100");
	if (!hundred)
	{
		free(result);
		return (NULL);
	}
	result = append_word(result, hundred);
	return (result);
}

char	*add_rest_to_result(t_dict *dict, char *result, char *rest)
{
	char	*word;
	char	*final;

	if (rest[0] == '0' && rest[1] == '0')
		return (result);
	word = convert_under_100(dict, rest);
	if (!word)
		return (result);
	final = append_word(result, word);
	free(word);
	return (final);
}
