/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:12:56 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/09 18:14:10 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0
# define EVEN(nbr) (nbr % 2 == 0)
# include <unistd.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;
void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif 