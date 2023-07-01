/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:41:22 by oroy              #+#    #+#             */
/*   Updated: 2023/06/30 22:14:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	chunk_add(t_list *head_a, int *sorted, size_t chunk_size, size_t count)
{
	int		chunks_num;
	size_t	i;

	i = 0;
	chunks_num = 0;
	while (i < count)
	{
		head_a->chunk = chunk_getindex(head_a->content, sorted, chunk_size);
		if (head_a->chunk > chunks_num)
			chunks_num = head_a->chunk;
		head_a = head_a->next;
		i++;
	}
	return (chunks_num);
}
