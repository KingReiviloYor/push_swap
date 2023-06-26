/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:37:22 by oroy              #+#    #+#             */
/*   Updated: 2023/06/26 16:36:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_checkargs(t_stack **stacks, char **argv, size_t *count)
{
	size_t	i;
	size_t	j;
	size_t	j_save;
	int		algo_do;

	i = 1;
	algo_do = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
				j++;
			if (!argv[i][j])
				break ;
			j_save = j;
			if (!ft_isint(argv[i], &j))
				ft_error(stacks);
			// ft_sendarg(stacks, argv[i], j_save, j);
			ft_sendarg(stacks, &argv[i][j_save], j - j_save, &algo_do);
			(*count)++;
		}
		i++;
	}
	return (algo_do);
}
