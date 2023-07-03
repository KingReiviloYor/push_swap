/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:54:33 by oroy              #+#    #+#             */
/*   Updated: 2023/07/03 19:47:26 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static size_t	get_node_position(t_stack *stacks)
{
	t_list	*pos;
	size_t	i;

	i = 0;
	pos = stacks->head_a;
	while (pos->next != stacks->head_a)
	{
		if (pos->content < stacks->head_b->content
			&& pos->next->content > stacks->head_b->content)
			break ;
		pos = pos->next;
		i++;
	}
	if (!i)
		i = 1;
	return (i);
}

static int	getindex_lowest(t_list *head)
{
	t_list	*pos;
	int	lowest;
	size_t	i;

	i = 1;
	lowest = 0;
	pos = head;
	while (pos->next != head)
	{
		lowest = pos->content;
		pos = pos->next;
		if (pos->content < lowest)
			break ;
		i++;
	}
	return (i);
}

static void	rotate_a(t_stack **stacks, int push_b)
{
	size_t	r_times;
	size_t	lstsize;
	size_t	idx;

	lstsize = ft_lstsize((*stacks)->head_a);
	if (push_b)
		idx = get_node_position(*stacks);
	else
		idx = getindex_lowest((*stacks)->head_a);
	if (idx <= lstsize / 2)
		r_times = idx;
	else
		r_times = lstsize - idx;
	while (r_times)
	{
		if (idx <= lstsize / 2)
			ra(stacks);
		else
			rra(stacks);
		r_times--;
	}
}

void	b_to_a(t_stack **stacks)
{
	size_t	r_times;
	size_t	lstsize;
	size_t	idx;

	idx = 0;
	lstsize = 0;
	r_times = 0;
	while ((*stacks)->head_b)
	{
		if (!(*stacks)->head_a || (*stacks)->head_a->next == (*stacks)->head_a
			|| ((*stacks)->head_a->content < (*stacks)->head_a->prev->content
			&& (*stacks)->head_b->content < (*stacks)->head_a->content)
			|| ((*stacks)->head_a->prev->content < (*stacks)->head_a->content
			&& (*stacks)->head_a->content > (*stacks)->head_b->content
			&& (*stacks)->head_a->prev->content < (*stacks)->head_b->content)
			|| ((*stacks)->head_a->prev->content > (*stacks)->head_a->content
			&& (*stacks)->head_b->content > (*stacks)->head_a->prev->content))
			pa(stacks);
		else
			rotate_a(stacks, 1);
	}
	if ((*stacks)->head_a->content > (*stacks)->head_a->prev->content)
		rotate_a(stacks, 0);
}
