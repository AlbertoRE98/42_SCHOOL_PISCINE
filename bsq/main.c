/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:57:48 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 10:20:09 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_single_map(int fd)
{
	char	*content;
	t_map	*map;

	content = read_file(fd);
	if (!content)
	{
		print_error();
		return ;
	}
	map = process_map_string(content);
	free(content);
	if (!map || !validate_map(map))
	{
		print_error();
		free_map(map);
		return ;
	}
	solve_bsq(map);
	print_map(map);
	free_map(map);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
	{
		process_single_map(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
			print_error();
		else
		{
			process_single_map(fd);
			close(fd);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
