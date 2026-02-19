/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:19:28 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 19:11:28 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	calculate_group_start(char *num_str, int index, int total, int *group_len)
{
	int	start;

	start = ft_strlen(num_str) - ((total - index) * 3);
	if (start < 0)
	{
		*group_len = ft_strlen(num_str) - ((total - index - 1) * 3);
		return (0);
	}
	*group_len = 3;
	return (start);
}

char	*extract_group(char *num_str, int index, int total)
{
	int		start;
	int		group_len;
	char	*group;
	int		i;

	start = calculate_group_start(num_str, index, total, &group_len);
	group = malloc(group_len + 1);
	if (!group)
		return (NULL);
	i = 0;
	while (i < group_len)
	{
		group[i] = num_str[start + i];
		i++;
	}
	group[i] = '\0';
	return (group);
}

char	*convert_group_helper(t_dict *dict, char *group, int power)
{
	char	*word;
	char	*scale;
	char	*result;

	word = convert_hundreds(dict, group);
	if (!word)
		return (NULL);
	if (power > 0)
	{
		scale = get_scale(dict, power);
		if (!scale)
		{
			free(word);
			return (NULL);
		}
		result = append_word(word, scale);
		return (result);
	}
	return (word);
}

int	is_zero_group(char *group)
{
	int	i;

	i = 0;
	while (group[i])
	{
		if (group[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*trim_leading_space(char *str)
{
	char	*trimmed;
	int		i;
	int		j;

	if (!str || str[0] != ' ')
		return (str);
	i = 0;
	while (str[i] == ' ')
		i++;
	trimmed = malloc(ft_strlen(str + i) + 1);
	if (!trimmed)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (str[i])
		trimmed[j++] = str[i++];
	trimmed[j] = '\0';
	free(str);
	return (trimmed);
}
