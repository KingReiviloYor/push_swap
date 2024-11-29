/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:41:22 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 17:00:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	chunk_add(t_list *head_a, int *sorted, size_t nodes_nbr, size_t count)
{
	size_t	chunks_nbr;
	size_t	i;

	i = 0;
	chunks_nbr = 0;
	while (i < count)
	{
		head_a->chunk = chunk_getindex(head_a->content, sorted, nodes_nbr);
		if (head_a->chunk > chunks_nbr)
			chunks_nbr = head_a->chunk;
		head_a = head_a->next;
		i++;
	}
	return (chunks_nbr);
}
