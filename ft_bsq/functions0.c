/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozennou <mozennou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:01:07 by mozennou          #+#    #+#             */
/*   Updated: 2023/09/06 12:25:46 by mozennou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	min(int a, int b, int c)
{
	if (a <= b)
	{
		if (b <= c)
			return (a);
		else if (c <= a)
			return (c);
	}
	if (c <= b)
		return (c);
	return (b);
}
