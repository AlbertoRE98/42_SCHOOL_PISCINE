/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:15:21 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/03 09:15:22 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_len(char *base)
{
	int	cont;

	cont = 0;
	while (base[cont] != '\0')
	{
		cont++;
	}
	return (cont);
}

int	valid_and_size(char *base)
{
	int	str_lengh_and_val;
	int	cont_loop_1;
	int	cont_loop_2;

	cont_loop_1 = 0;
	str_lengh_and_val = ft_str_len(base);
	if (str_lengh_and_val < 2)
		return (0);
	while (base[cont_loop_1] != '\0')
	{
		if (base[cont_loop_1] == '+' || base[cont_loop_1] == '-'
			|| base[cont_loop_1] == ' '
			|| (base[cont_loop_1] >= 9 && base[cont_loop_1] <= 13))
			return (0);
		cont_loop_2 = cont_loop_1 + 1;
		while (base[cont_loop_2] != '\0')
		{
			if (base[cont_loop_1] == base[cont_loop_2])
				return (0);
			cont_loop_2++;
		}
		cont_loop_1++;
	}
	return (str_lengh_and_val);
}

int	get_weight_nb(char c, char *base)
{
	int	counter;

	counter = 0;
	while (base[counter] != '\0')
	{
		if (base[counter] == c)
			return (counter);
		counter++;
	}
	return (-1);
}

int	atoi_ptr_ch(char *str, char *base, int size, int acumulator)
{
	int	value;
	int	next_res;

	value = get_weight_nb(*str, base);
	if (value == -1)
		return (acumulator);
	next_res = (acumulator * size) + value;
	return (atoi_ptr_ch(str + 1, base, size, next_res));
}

int	ft_atoi_base(char *str, char *base)
{
	int	size_b;
	int	acumulator;
	int	cnt;
	int	sign;

	sign = 1;
	cnt = 0;
	acumulator = 0;
	size_b = valid_and_size (base);
	if (size_b == 0)
		return (0);
	while (str[cnt] == ' ' || (str[cnt] >= '\t' && str[cnt] <= '\r'))
	{
		cnt++;
	}
	while (str[cnt] == '-' || str[cnt] == '+')
	{
		if (str[cnt] == '-')
			sign *= -1;
		cnt++;
	}
	return (atoi_ptr_ch(str + cnt, base, size_b, acumulator) * sign);
}
