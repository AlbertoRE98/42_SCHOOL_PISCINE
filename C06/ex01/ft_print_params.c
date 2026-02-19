/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:59:44 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 13:21:07 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	count;
	int	aux_escr;

	count = 1;
	while (count < argc)
	{
		aux_escr = 0;
		while (argv[count][aux_escr])
		{
			write (1, &argv[count][aux_escr], 1);
			aux_escr++;
		}
		write (1, "\n", 1);
		count++;
	}
	return (0);
}
