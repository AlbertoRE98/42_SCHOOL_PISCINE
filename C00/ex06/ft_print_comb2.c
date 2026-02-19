/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:02:03 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 19:41:55 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		decens;
	int		units;
	char	c;

	decens = 0;
	while (decens <= 98)
	{
		units = decens + 1;
		while (units <= 99)
		{
			c = (decens / 10 + '0' );
			write (1, &c, 1);
			c = (decens % 10 + '0');
			write(1, &c, 1);
			write(1, " ", 1);
			c = (units / 10 + '0' );
			write (1, &c, 1);
			c = (units % 10 + '0');
			write(1, &c, 1);
			if (!(decens == 98 && units == 99))
				write(1, ", ", 2);
			units++;
		}
		decens++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/