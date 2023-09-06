/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:01:51 by mozennou          #+#    #+#             */
/*   Updated: 2023/09/06 17:04:34 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
}

int	ft_atoi2(char *s, int ind)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] && i < ind)
	{
		if (!(s[i] <= '9' && s[i] >= '0'))
			return (0);
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res);
}

int	cbytes(char *file)
{
	int		b;
	char	bf[1024];
	int		fd;
	int		res;

	res = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	b = read(fd, bf, 1024);
	while (b > 0)
	{
		res += b;
		b = read(fd, bf, 1024);
	}
	close (fd);
	if (b > 0)
		return (-1);
	return (res);
}

int	put_err(int k)
{
	if (k == 1)
		ft_putstr("Cannot read the file\n");
	if (k == 2)
		ft_putstr("map error\n");
	if (k == 3)
		ft_putstr("Error: memory allocation\n");
	return (-1);
}

int	is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (0);
	return (1);
}
