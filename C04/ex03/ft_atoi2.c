/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:14:56 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/05 21:09:25 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	digit_value(char c)
{
	int	valor_c;

	valor_c = 0;
	if (c >= '0' && c <= '9')
		valor_c = c - '0';
	return (valor_c);
}

int	ft_atoi2(char *str)
{
	int	sign;
	int	acum;

	acum = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		acum = (acum * 10) + digit_value(*str);
		str++;
	}
	return (acum * sign);
}
