/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:41:38 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 19:19:58 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*convert_hundreds(t_dict *dict, char *group)
{
	char	*result;
	char	rest[3];

	if (ft_strlen(group) < 3 || group[0] == '0')
		return (convert_under_100(dict, group));
	result = process_hundred_digit(dict, group[0]);
	if (!result)
		return (NULL);
	rest[0] = group[1];
	rest[1] = group[2];
	rest[2] = '\0';
	return (add_rest_to_result(dict, result, rest));
}

char	*get_scale(t_dict *dict, int power)
{
	char	scale_num[1200];
	int		i;

	if (power <= 0)
		return (NULL);
	scale_num[0] = '1';
	i = 1;
	while (i <= power)
	{
		scale_num[i] = '0';
		i++;
	}
	scale_num[i] = '\0';
	return (find_in_dictionary(dict, scale_num));
}

int	count_groups(char *num_str)
{
	int	len;

	len = ft_strlen(num_str);
	if (len == 0)
		return (0);
	return ((len + 2) / 3);
}
