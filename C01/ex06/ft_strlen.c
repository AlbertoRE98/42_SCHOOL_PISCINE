/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:15:36 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/01 11:15:38 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	char	aux;
	int		cont;

	cont = 0;
	aux = *str;
	while (aux != '\0')
	{
		cont++;
		str++;
		aux = *str;
	}
	return (cont);
}
