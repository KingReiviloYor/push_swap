/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:41:22 by oroy              #+#    #+#             */
/*   Updated: 2023/06/27 17:52:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_addchunk(t_list *head_a, int *sorted, size_t chunk_size)
{
	int	chunks_num;

	chunks_num = 0;
	while (head_a)
	{
		head_a->chunk = ft_getchunkindex(head_a->content, sorted, chunk_size);
		if (head_a->chunk > chunks_num)
			chunks_num = head_a->chunk;
		head_a = head_a->next;
	}
	return (chunks_num);
}
