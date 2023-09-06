/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:27:51 by mozennou          #+#    #+#             */
/*   Updated: 2023/09/06 19:45:37 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BF_SIZE 100000000

typedef struct s_cords {
	int	x;
	int	y;
	int	len;
}	t_cords;

typedef struct s_info {
	char	emp;
	char	ful;
	char	obs;
	int		height;
	int		width;
}	t_info;

void	ft_putchar(char c);
int		min(int a, int b, int c);
void	ft_putstr(char *s);
int		ft_atoi2(char *s, int n);
int		cbytes(char *file);
int		put_err(int k);
int		is_printable(char c);
int		str_map(char *file, char **map);
int		get_width(char *map, int i, t_info *inf);
int		valide_map(char *map, t_info *inf);
int		int_map(char *a, t_info **inf, int ***mat);
int		**convert_map(char *map, t_info *inf);
int		std_in(t_info **inf, int ***mat);
void	fill_line(int *t, char *map, int *i, t_info *inf);
int		**set_squares(int **map, t_info *map_info);
t_cords	get_bsq(int **map, t_info *map_info); 
void	print_map(int	**map, t_info *map_info, t_cords cords);
int		idenitique(t_info *inf);
void	ft_free(int **mat, t_info *inf, t_cords *cords);
void	bsq(char *a);

#endif
