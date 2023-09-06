/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:05:35 by mozennou          #+#    #+#             */
/*   Updated: 2023/09/06 18:51:51 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fill_line(int *t, char *map, int *i, t_info *inf)
{
	int	k;

	k = 0;
	while (map[*i] && map[*i] != '\n')
	{
		if (map[*i] == inf->emp)
			t[k] = 1;
		else if (map[*i] == inf->obs)
			t[k] = 0;
		k++;
		(*i)++;
	}
}

int	std_in(t_info **inf, int ***mat)
{
	int		i;
	char	*bf;
	int		b;

	i = 0;
	(*inf) = (t_info *)malloc(sizeof(t_info));
	bf = (char *)malloc(sizeof(char) * (BF_SIZE + 1));
	if (bf == NULL)
		return (put_err(3));
	b = read(0, bf, BF_SIZE);
	if (valide_map(bf, *inf) == -1)
		return (put_err(2));
	(*mat) = convert_map(bf, *inf);
	free (bf);
	if ((*mat) == NULL)
		exit(0);
	return (0);
}
