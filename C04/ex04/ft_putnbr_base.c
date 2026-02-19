/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:36:57 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/03 07:36:59 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	contador;

	contador = 0;
	while (base[contador])
	{
		contador++;
	}
	return (contador);
}

int	valid(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base [i] == base [j])
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '-' || base[i] == '+' )
			return (0);
		i++;
	}
	if (ft_strlen(base) < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char		nmb_conv[32];			
	int			cont;
	long int	n;

	cont = 0;
	if (valid(base) == 0)
		return ;
	n = nbr;
	if (nbr < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n == 0)
		nmb_conv[cont++] = base[0];
	while (n > 0)
	{
		nmb_conv[cont++] = base [n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	while (cont > 0)
	{
		cont --;
		write (1, &nmb_conv[cont], 1);
	}
}
/*
int main(void)
{
    
    write(1, "Decimal: ", 9);
    ft_putnbr_base(123, "0123456789");
    write(1, "\n", 1);

  
    write(1, "Binario: ", 9);
    ft_putnbr_base(13, "01");
    write(1, "\n", 1);

    
    write(1, "Hexa:    ", 9);
    ft_putnbr_base(-2378761, "0123456789ABCDEF");
    write(1, "\n", 1);

    
    write(1, "Base abc: ", 10);
    ft_putnbr_base(10, "abc"); 
    write(1, "\n", 1);

    return (0);
}
*/
