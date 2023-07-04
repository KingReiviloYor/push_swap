/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:51:01 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 17:09:42 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	a_to_b(t_stack **stacks, size_t min_n, size_t min, size_t max)
{
	pb(stacks);
	if ((*stacks)->head_b->chunk == min
		&& (*stacks)->head_b->next != (*stacks)->head_b)
	{
		if ((*stacks)->head_a
			&& (*stacks)->head_a->chunk != max
			&& (*stacks)->head_a->chunk != min
			&& !((*stacks)->head_a->chunk == min - 1 && !min_n))
			rr(stacks);
		else
			rb(stacks);
	}
}
