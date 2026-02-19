/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:15:32 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/11 13:11:38 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_wr_str(char *str)
{
	int		cont;

	cont = 0;
	while (str[cont])
	{
		write(1, &str[cont], 1);
		cont++;
	}
	write (1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write (1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	cont;

	cont = 0;
	while (par[cont].str != 0)
	{
		ft_wr_str(par[cont].str);
		ft_putnbr(par[cont].size);
		write (1, "\n", 1);
		ft_wr_str(par[cont].copy);
		cont++;
	}
}
