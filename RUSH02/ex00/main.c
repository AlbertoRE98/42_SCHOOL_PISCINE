/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:15:50 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 19:09:01 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	handle_args(int argc, char **argv, char **dict_file, char **num_str)
{
	if (argc < 2 || argc > 3)
	{
		ft_put_str("Error\n", 1);
		return (0);
	}
	if (argc == 2)
	{
		*dict_file = DEFAULT_DIC;
		*num_str = argv[1];
	}
	else
	{
		*dict_file = argv[1];
		*num_str = argv[2];
	}
	return (1);
}

int	process_and_display(t_dict *dict, char *num_str)
{
	char	*result;

	result = convert_number(dict, num_str);
	if (!result)
	{
		ft_put_str("Dict Error\n", 1);
		return (0);
	}
	ft_put_str(result, 1);
	ft_put_str("\n", 1);
	free(result);
	return (1);
}

int	init_and_parse_dict(t_dict *dict, char *dict_file)
{
	init_dict(dict);
	if (!parse_dict_in_file(dict, dict_file))
	{
		ft_put_str("Dict Error\n", 1);
		free_memory_dict(dict);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dict	dict;
	char	*dict_file;
	char	*num_str;

	if (!handle_args(argc, argv, &dict_file, &num_str))
		return (1);
	if (!is_valid_number(num_str))
	{
		ft_put_str("Error\n", 1);
		return (1);
	}
	if (!init_and_parse_dict(&dict, dict_file))
	{
		ft_put_str("Dict Error\n", 1);
		return (1);
	}
	if (!process_and_display(&dict, num_str))
	{
		free_memory_dict(&dict);
		return (1);
	}
	free_memory_dict(&dict);
	return (0);
}
