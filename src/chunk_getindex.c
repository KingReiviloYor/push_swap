/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_getindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:57:51 by oroy              #+#    #+#             */
/*   Updated: 2023/06/30 22:14:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	chunk_getindex(int content, int *arr, size_t chunk_size)
{
	int		i_chunk;
	size_t	i;

	i = 0;
	i_chunk = 1;
	while (arr[i] != content)
	{
		i++;
		if (i % chunk_size == 0)
			i_chunk++;
	}
	return (i_chunk);
}
