/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/27 19:28:57 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_result(t_stack *stacks)
// {
// 	if (stacks->head_a)
// 		stacks->head_a->prev->next = NULL;
// 	if (stacks->head_b)
// 		stacks->head_b->prev->next = NULL;
// 	ft_printf ("\n");
// 	ft_printf ("a	b");
// 	ft_printf ("\n\n");
// 	while (stacks->head_a || stacks->head_b)
// 	{
// 		if (stacks->head_a)
// 		{
// 			ft_printf ("%i", stacks->head_a->content);
// 			stacks->head_a = stacks->head_a->next;
// 		}
// 		ft_printf ("	");
// 		if (stacks->head_b)
// 		{
// 			ft_printf ("%i", stacks->head_b->content);
// 			stacks->head_b = stacks->head_b->next;
// 		}
// 		ft_printf ("\n");
// 	}
// 	ft_printf ("\n\n");
// }

// void	ft_displaychunks(t_stack *stacks)
// {
// 	t_list	*head;

// 	head = stacks->head_a;
// 	while (head)
// 	{
// 		printf ("%i", head->chunk);
// 		printf (" - ");
// 		printf ("%i\n", head->content);
// 		head = head->next;
// 	}
// }

void	chunk_sort(t_stack **stacks, size_t count)
{
	int	*sorted;
	int	chunks_num;
	int	chunk_div;

	sorted = ft_calloc(count, sizeof(int));
	if (!sorted)
		ft_error(stacks);
	sorted = ft_lstoarray(sorted, (*stacks)->head_a);
	sorted = ft_sortarray(sorted, count);
	chunk_div = ft_getchunkdiv(count);
	chunks_num = ft_addchunk((*stacks)->head_a, sorted, count / chunk_div + 1);
	(*stacks)->head_a->prev->next = (*stacks)->head_a;
	ft_algo(stacks, chunks_num, count / chunk_div + 1);
}

void	basic_sort(t_stack **stacks, size_t count)
{
	(*stacks)->head_a->prev->next = (*stacks)->head_a;
	if (count == 2
		|| ((*stacks)->head_a->prev->content > (*stacks)->head_a->content
		&& (*stacks)->head_a->prev->content > (*stacks)->head_a->next->content))
		sa(stacks);
	else if ((*stacks)->head_a->content > (*stacks)->head_a->next->content
		&& (*stacks)->head_a->content > (*stacks)->head_a->prev->content
		&& (*stacks)->head_a->next->content > (*stacks)->head_a->prev->content)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (((*stacks)->head_a->prev->content < (*stacks)->head_a->content
		&& (*stacks)->head_a->prev->content > (*stacks)->head_a->next->content))
		ra(stacks);
	else if ((*stacks)->head_a->content < (*stacks)->head_a->next->content
		&& (*stacks)->head_a->content > (*stacks)->head_a->prev->content)
		rra(stacks);
	else if ((*stacks)->head_a->content < (*stacks)->head_a->next->content
		&& (*stacks)->head_a->content < (*stacks)->head_a->prev->content)
	{
		rra(stacks);
		sa(stacks);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	size_t	count;

	if (argc > 1)
	{
		count = 0;
		stacks = ft_stacknew();
		if (!stacks)
			ft_error(&stacks);
		if (ft_checkargs(&stacks, argv, &count))
		{
			if (count == 2 || count == 3)
				basic_sort(&stacks, count);
			else
				chunk_sort(&stacks, count);
			// ft_displaychunks(stacks);
			// ft_result(stacks);
		}
	}
	return (0);
}
