/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_getindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:57:51 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 17:05:08 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	chunk_getindex(int content, int *arr, size_t nodes_nbr)
{
	size_t	i_chunk;
	size_t	i;

	i = 0;
	i_chunk = 1;
	while (arr[i] != content)
	{
		i++;
		if (i % nodes_nbr == 0)
			i_chunk++;
	}
	return (i_chunk);
}
