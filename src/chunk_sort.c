/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:39:51 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 16:55:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	chunk_sort(t_stack **stacks, size_t count)
{
	size_t	chunks_nbr;
	size_t	nodes_nbr;
	int		*sorted;

	sorted = ft_calloc(count, sizeof(int));
	if (!sorted)
		ft_error(stacks);
	sorted = lstoarray(sorted, (*stacks)->head_a, count);
	sorted = sortarray(sorted, count);
	nodes_nbr = chunk_nodes_amount(count);
	chunks_nbr = chunk_add((*stacks)->head_a, sorted, nodes_nbr, count);
	free (sorted);
	sorted = NULL;
	algo(stacks, chunks_nbr, nodes_nbr);
}
