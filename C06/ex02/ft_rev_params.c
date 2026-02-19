/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:13:35 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 13:21:06 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	cont;
	int	aux_escr;

	cont = argc - 1;
	while (cont >= 1)
	{
		aux_escr = 0;
		while (argv[cont][aux_escr])
		{
			write(1, &argv[cont][aux_escr], 1);
			aux_escr++;
		}
		write(1, "\n", 1);
		cont--;
	}
	return (0);
}
