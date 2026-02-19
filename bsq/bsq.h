/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:39:20 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/17 10:17:19 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/*
Lo mas lógico esque el mapa este conformado por
filas, columnas, y que podamos identificar 
que tipo de caracter esta asociado. 
El grid al final consiste en una matriz, 
con una columna y una fila que vas accediendo 
por indices a donde sea necesario.
*/
typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_square
{
	int	row;
	int	col;
	int	size;
}	t_square;

/*
Funciones de lectura del archivo
vamos a guardar todo en un buffer gigantte
y vamos a sacar los valores a partir de ahi
lo que necsitemos para guardarlo
*/
int		get_map_params(t_map *map, char *str);
int		get_map_cols(char *str);
int		allocate_map_memory(t_map *map);
int		fill_grid_data(t_map *map, char *str);
t_map	*process_map_string(char *file_content);
char	*read_file(int fd);
/*
funciones de validaciones de errores
*/
int		validate_map(t_map *map);
int		check_characters(t_map *map);
/*
funciones auxiliares que seran
necesarias mas adelante, escritura
de strings, liberacion de memoria, etc
*/
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);
void	copy_buffer(char *content, char *buffer, int to_size, int bytes_read);
void	free_map(t_map *map);
/*
funciones para la resolucion del problema
e intentar encontrar el mejor de todas
las soluciones
*/
int		get_min_val(int a, int b, int c);
void	process_cell(t_map *map, int **arr, int *pos, t_square *best);
void	solve_bsq(t_map *map);
void	free_int_tab(int **arr, int rows);

/*
funciones para hacer un print de lo que sea
*/
void	print_map(t_map *map);
void	draw_square(t_map *map, t_square sq);
void	print_error(void);
/*
funciones del main para 
manejar los errores
y excepciones
*/

#endif