/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:48:56 by oroy              #+#    #+#             */
/*   Updated: 2023/06/16 18:17:08 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	off_limits(unsigned int nbr, int minus, char c)
{
	if (nbr > 214748364 || (nbr == 214748364 && c > '7' && minus == 1)
		|| (nbr == 214748364 && c == '9' && minus == -1))
		return (0);
	return (1);
}

int	ft_isint(char *str, size_t *i)
{
	unsigned int	nbr;
	int				minus;

	if (!str)
		return (0);
	nbr = 0;
	minus = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			minus = -1;
		*i += 1;
	}
	while (str[*i] && str[*i] != 32 && !(str[*i] >= 9 && str[*i] <= 13))
	{
		if (!ft_isdigit(str[*i]) || !off_limits(nbr, minus, str[*i]))
			return (0);
		nbr *= 10;
		nbr += str[*i] - 48;
		*i += 1;
	}
	if (!ft_isdigit(str[*i - 1]))
		return (0);
	return (1);
}
