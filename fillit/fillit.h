/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:19:37 by hunnamab          #+#    #+#             */
/*   Updated: 2019/12/23 13:00:46 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

typedef struct			s_tetrimino
{
	uint64_t			tet;
	unsigned char		b;
	unsigned char		x;
	unsigned char		y;
	unsigned char		wid;
	unsigned char		hei;
	struct s_tetrimino	*next;
}						t_list;

t_list					*create_list(uint64_t *tet, int y);
int						mistakes_output(int fd);
int						check_mistakes(int fd);
int						check_tetrm(char **arr, int cnt);
uint64_t				*get_dec_arr(int fd);
uint64_t				ft_btd(char *bin);
uint64_t				ft_pow(uint64_t x, uint64_t y);
int						fillit(t_list *list, t_list *list_const, int y);
void					map_output(t_list *list, int y, int size);
void					big_map_output(int size, t_list *list, \
						size_t i, size_t z);
void					clear_list(t_list *list, t_list *list_const, int y);
int						fillit_big(t_list *list, uint16_t *map, int size);
int						control(t_list *list, int size, \
						t_list *list_const, int y);
void					zero(char *arr, int start, int end);
char					*ft_strsub_x2(char const *s, unsigned int start, \
						size_t len);
char					**bin_strsplit(char *buf, int cnt);
uint64_t				min_y(uint64_t tet);
uint64_t				min_x(uint64_t tet);
void					make_it_zero(uint16_t *map);
void					print_map(char *map, int size, size_t map_size);
char					*create_map(size_t map_size);
void					double_arr_free(char **arr, int y);
void					free_list(t_list *list);

#endif
