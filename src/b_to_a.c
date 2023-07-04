/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:54:33 by oroy              #+#    #+#             */
/*   Updated: 2023/07/04 17:31:13 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	getindex_lowest(t_list *head)
{
	t_list	*pos;
	int		lowest;
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

static int	check_push_a(t_list *head_a, t_list *head_b)
{
	if (!head_a || head_a->next == head_a
		|| (head_a->content < head_a->prev->content
			&& head_b->content < head_a->content)
		|| (head_a->prev->content < head_a->content
			&& head_a->content > head_b->content
			&& head_a->prev->content < head_b->content)
		|| (head_a->prev->content > head_a->content
			&& head_b->content > head_a->prev->content))
		return (1);
	else
		return (0);
}

void	b_to_a(t_stack **stacks)
{
	while ((*stacks)->head_b)
	{
		if (check_push_a((*stacks)->head_a, (*stacks)->head_b))
			pa(stacks);
		else
			rotate_a(stacks, 1);
	}
	if ((*stacks)->head_a->content > (*stacks)->head_a->prev->content)
		rotate_a(stacks, 0);
}
