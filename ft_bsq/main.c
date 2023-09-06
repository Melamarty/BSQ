/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:20:00 by mel-amar          #+#    #+#             */
/*   Updated: 2023/09/06 18:26:47 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

void	ft_free(int **mat, t_info *inf, t_cords *cords)
{
	int	i;

	i = 0;
	while (i < inf->height && mat[i] != NULL)
	{
		free(mat[i]);
		i++;
	}
	if (mat != NULL)
		free(mat);
	if (inf != NULL)
		free(inf);
	if (cords != NULL)
		free(cords);
}

void	bsq(char *a)
{
	int		**mat;
	t_info	*inf;
	t_cords	*cords;

	cords = (t_cords *)malloc(sizeof(t_cords));
	if (a != NULL)
	{
		if (!int_map(a, &inf, &mat))
		{
			mat = set_squares(mat, inf);
			(*cords) = get_bsq(mat, inf);
			print_map(mat, inf, *cords);
			ft_free(mat, inf, cords);
		}
	}
	else
	{
		if (!std_in(&inf, &mat))
		{
			mat = set_squares(mat, inf);
			(*cords) = get_bsq(mat, inf);
			print_map(mat, inf, *cords);
			ft_free(mat, inf, cords);
		}
	}
}

int	main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			bsq(av[i]);
			if (i < ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		bsq(NULL);
	}
	return (0);
}
