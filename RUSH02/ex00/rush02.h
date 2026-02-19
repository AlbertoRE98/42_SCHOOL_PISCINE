/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:17:55 by aramos-e          #+#    #+#             */
/*   Updated: 2026/02/15 18:46:16 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define DEFAULT_DIC "numbers.dict"
# define BUFFER_SIZE 4096
# define STARTER_CAPACITY 256

typedef struct s_entry
{
	char	*number;
	char	*word;
}	t_entry;

typedef struct s_dict
{
	t_entry	*entries;
	int		count;
	int		capacity;
}	t_dict;

int		ft_is_digit(char digit);
int		ft_isspace(char character);
int		is_valid_number(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strdup(char *str);
char	*ft_str_cat(char *dest, char *src);
char	*ft_str_join(char *s1, char *s2);
void	ft_put_str(char *str, int ft);
char	*ft_strchr(const char *s, int c);

void	init_dict(t_dict *dict);
int		expand_dictionary(t_dict *dict);
void	free_memory_dict(t_dict *dict);
int		add_dict_entry_for_number(t_dict *dic, char *n, char *wd);
char	*find_in_dictionary(t_dict *dict, char *nb);

char	*normalize_nbr(char *str_nbr);
char	*remove_seps(char *str);
int		process_line(t_dict *dict, char *line);
int		parse_dict_in_file(t_dict *dict, char *filename);
char	*find_newline(char *str);
char	*join_buffers(char *old, char *new, int old_len, int new_len);
char	*process_read_block(char *content, char *temp, int total, int bytes);
char	*read_full_file(int fd);
int		process_buffer_reader(t_dict *dict, char *buffer);
int		process_single_line(t_dict *dict, char *start, char *newline);
char	*find_and_process_line(t_dict *dict, char *start, int *ok);

char	*append_word(char *pre_word, char *word);
char	*handle_two_digit_number(t_dict *dict, char *group);
char	*convert_under_100(t_dict *dict, char *group);
char	*convert_hundreds(t_dict *dict, char *group);
char	*process_hundred_digit(t_dict *dict, char digit);
char	*add_rest_to_result(t_dict *dict, char *result, char *rest);
char	*convert_group_helper(t_dict *dict, char *group, int power);
char	*get_scale(t_dict *dict, int power);
int		count_groups(char *num_str);
int		calculate_group_start(char *num_str, int index, int total, int *gl);
char	*extract_group(char *num_str, int index, int total);
int		is_zero_group(char *group);
char	*trim_leading_space(char *str);
char	*process_single_group(t_dict *dict, char *num_str, int i, int total);
char	*convert_number(t_dict *dict, char *num_str);

int		handle_args(int argc, char **argv, char **dict_file, char **num_str);
int		process_and_display(t_dict *dict, char *num_str);
int		init_and_parse_dict(t_dict *dict, char *dict_file);

#endif