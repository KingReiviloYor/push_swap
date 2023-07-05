/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:37:22 by oroy              #+#    #+#             */
/*   Updated: 2023/07/05 11:32:42 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sendarg(t_stack **stacks, char *s, size_t len, int *algo_do)
{
	char	*str;

	str = ft_substr(s, 0, len);
	if (!str)
		ft_error(stacks);
	parsing(stacks, ft_atoi(str), &str, algo_do);
}

int	checkargs(t_stack **stacks, char **argv, size_t *count)
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
			sendarg(stacks, &argv[i][j_save], j - j_save, &algo_do);
			(*count)++;
		}
		i++;
	}
	return (algo_do);
}
