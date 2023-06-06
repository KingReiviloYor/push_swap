/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:48:56 by oroy              #+#    #+#             */
/*   Updated: 2023/06/05 15:10:22 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	off_limits(unsigned int nbr, int minus, char c)
{
	if (nbr > 214748364 || (nbr == 214748364 && c > '7' && minus == 1)
		|| (nbr == 214748364 && c == '9' && minus == -1))
		return (0);
	return (1);
}

int	ft_isint(char *str)
{
	unsigned int	nbr;
	int				minus;

	if (!str)
		return (0);
	nbr = 0;
	minus = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str) || !off_limits(nbr, minus, *str))
			return (0);
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (!ft_isdigit(*(str - 1)))
		return (0);
	return (1);
}
