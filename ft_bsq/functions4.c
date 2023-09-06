/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:09:09 by mozennou          #+#    #+#             */
/*   Updated: 2023/09/06 12:26:49 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"

int	**set_squares(int **map, t_info *map_info)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (map[i][j] && i != 0 && j != 0)
			{
				a = map[i - 1][j];
				map[i][j] = min(a, map[i - 1][j - 1], map[i][j - 1]);
				map[i][j]++;
			}
		}
	}
	return (map);
}

t_cords	get_bsq(int **map, t_info *map_info)
{
	int		i;
	int		j;
	int		max;
	t_cords	cords;

	i = -1;
	max = 0;
	cords.x = 0;
	cords.y = 0;
	cords.len = 0;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (map[i][j] > max)
			{
				max = map[i][j];
				cords.x = i;
				cords.y = j;
				cords.len = max;
			}
		}
	}
	return (cords);
}

void	print_map(int	**map, t_info *map_info, t_cords cords)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (map[i][j] == 0)
				ft_putchar(map_info->obs);
			else if (i > cords.x - cords.len && i <= cords.x 
				&& j > cords.y - cords.len && j <= cords.y)
				ft_putchar(map_info->ful);
			else
				ft_putchar(map_info->emp);
		}
		ft_putchar('\n');
	}
}

int	idenitique(t_info *inf)
{
	if (inf->obs == inf->ful || inf->obs == inf->emp || inf->emp == inf->ful)
		return (0);
	return (1);
}
