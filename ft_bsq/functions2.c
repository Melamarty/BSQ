/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:03:07 by mozennou          #+#    #+#             */
/*   Updated: 2023/09/06 18:49:31 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "header.h"

int	str_map(char *file, char **map)
{
	int		fd;
	int		b;
	int		i;
	char	bf;

	if (cbytes(file) == -1)
		return (1);
	(*map) = (char *)malloc(sizeof(char) * (cbytes(file) + 1));
	if ((*map) == NULL)
		return (3);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	b = read(fd, &bf, 1);
	while (b > 0)
	{
		(*map)[i++] = bf;
		b = read(fd, &bf, 1);
	}
	if (b == -1)
		return (1);
	close (fd);
	(*map)[i] = '\0';
	return (0);
}

int	get_width(char *map, int i, t_info *inf)
{
	int	len;
	int	j;

	len = 0;
	while (map[i] && map[i] != '\n')
	{
		len++;
		i++;
	}
	if (len == 0)
		return (-1);
	j = ++i;
	while (map[i])
	{
		if (map[i] != '\n' && map[i] != inf->obs && map[i] != inf->emp)
			return (-1);
		if (map[i] == '\n')
		{
			if (len != i - j)
				return (-1);
			j = i + 1;
		}
		i++;
	}
	return (len);
}

int	valide_map(char *map, t_info *inf)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	if (i > 3)
	{
		inf->ful = map[--i];
		inf->obs = map[--i];
		inf->emp = map[--i];
		inf->height = ft_atoi2(map, i);
	}
	else
		return (-1);
	while (map[i] && map[i] != '\n')
		i++;
	inf->width = get_width(map, ++i, inf);
	if (inf->width == -1 || inf->height == 0 || !is_printable(inf->ful) || 
		!is_printable(inf->obs) || !is_printable(inf->emp) || !idenitique(inf))
		return (-1);
	return (0);
}

int	**convert_map(char *map, t_info *inf)
{
	int	i;
	int	j;
	int	**res;

	i = 0;
	j = 0;
	res = (int **)malloc(sizeof(int *) * (inf->height + 1));
	if (res == NULL)
		put_err(3);
	while (map[i] && map[i] != '\n')
		i++;
	i++;
	while (map[i])
	{
		res[j] = (int *)malloc(sizeof(int) * (inf->width + 1));
		fill_line(res[j], map, &i, inf);
		i++;
		j++;
	}
	if (j != inf->height)
	{
		put_err(2);
		return (NULL);
	}
	return (res);
}

int	int_map(char *file_name, t_info **inf, int ***mat)
{
	char	*map;
	int		err;

	(*inf) = (t_info *)malloc(sizeof(t_info));
	err = str_map(file_name, &map);
	if (err != 0)
		return (put_err(err));
	if (valide_map(map, *inf) == -1)
		return (put_err(2));
	(*mat) = convert_map(map, *inf);
	if ((*mat) == NULL)
		return (-1);
	free (map);
	return (0);
}
