/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:44:47 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 16:33:40 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	cont;

	(void)argc;
	cont = 0;
	while (argv[0][cont] != '\0')
	{
		write(1, &argv[0][cont], 1);
		cont++;
	}
	write (1, "\n", 1);
	return (0);
}
