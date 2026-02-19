/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:01:52 by aramos-e          #+#    #+#             */
/*   Updated: 2026/01/28 21:14:06 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	res;

	if (n >= 0)
	{
		res = 'P';
	}
	else
	{
		res = 'N';
	}
	write(1, &res, 1);
}

/*
int main(){

	ft_is_negative(3);
	ft_is_negative(-4);
	return 0;
}
*/
