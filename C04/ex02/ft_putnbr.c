/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:22:39 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/02 17:22:41 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pow_10(int number)
{
	int		aux;

	if (number < 0)
		number *= -1;
	aux = 1;
	while (number / 10 != 0)
	{
		aux *= 10;
		number /= 10;
	}
	return (aux);
}

void	ft_putnbr(int nb)
{
	char	digit;
	int		power;
	int		digito_n;

	power = pow_10(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (power != 0)
	{
		digito_n = nb / power;
		digit = digito_n + '0';
		nb -= digito_n * power;
		power /= 10;
		write(1, &digit, 1);
	}
}

/*
int main (void)
{
	int nb=42;
	ft_putnbr(nb);
	return (0);
}
*/