/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:21:11 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/04 17:51:16 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcomp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	write_str(char *s1)
{
	int	cont_char;

	cont_char = 0;
	while (s1[cont_char] != '\0')
	{
		write (1, &s1[cont_char], 1);
		cont_char++;
	}
}

int	main(int argc, char *argv[])
{
	int	cont_loop;
	int	cont_loop_2;

	cont_loop = 1;
	while (cont_loop < argc - 1)
	{
		cont_loop_2 = cont_loop + 1;
		while (cont_loop_2 < argc)
		{
			if (ft_strcomp(argv[cont_loop], argv[cont_loop_2]) > 0)
				swap_str(&argv[cont_loop], &argv[cont_loop_2]);
			cont_loop_2++;
		}
		cont_loop++;
	}
	cont_loop = 1;
	while (cont_loop < argc)
	{
		write_str(argv[cont_loop]);
		write(1, "\n", 1);
		cont_loop++;
	}
	return (0);
}
