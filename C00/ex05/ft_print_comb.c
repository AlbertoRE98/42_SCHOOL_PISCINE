/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:13:23 by aramos-e          #+#    #+#             */
/*   Updated: 2026/01/29 08:58:33 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	hundreds;
	int	decens;
	int	units;

	hundreds = '0';
	while (hundreds <= '7')
	{
		decens = hundreds + 1;
		while (decens <= '8')
		{
			units = decens + 1;
			while (units <= '9')
			{
				write(1, &hundreds, 1);
				write(1, &decens, 1);
				write(1, &units, 1);
				if (!(hundreds == '7' && decens == '8' && units == '9'))
					write(1, ", ", 2);
				units++;
			}
			decens++;
		}
		hundreds++;
	}
}

/*
int main(void)
{
	ft_print_comb();
	return 0;
}
*/