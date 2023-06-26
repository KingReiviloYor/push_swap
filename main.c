/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/26 19:36:53 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_result(t_stack *stacks, size_t count)
// {
// 	t_list	*head;
// 	size_t	i;

// 	i = 0;
// 	head = stacks->head_a;
// 	while (i < count)
// 	{
// 		ft_printf ("%i\n", head->content);
// 		head = head->next;
// 		i++;
// 	}
// }

void	ft_result(t_stack *stacks)
{
	if (stacks->head_a)
		stacks->head_a->prev->next = NULL;
	if (stacks->head_b)
		stacks->head_b->prev->next = NULL;
	ft_printf ("\n");
	ft_printf ("a	b");
	ft_printf ("\n\n");
	while (stacks->head_a || stacks->head_b)
	{
		if (stacks->head_a)
		{
			ft_printf ("%i", stacks->head_a->content);
			stacks->head_a = stacks->head_a->next;
		}
		ft_printf ("	");
		if (stacks->head_b)
		{
			ft_printf ("%i", stacks->head_b->content);
			stacks->head_b = stacks->head_b->next;
		}
		ft_printf ("\n");
	}
	ft_printf ("\n\n");
}

// void	ft_tests(t_stack **stacks)
// {
// 	pb(stacks);
// 	pb(stacks);
// 	ss(stacks);
// 	pb(stacks);
// 	ra(stacks);
// 	pa(stacks);
// 	pa(stacks);
// }

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	int		*sorted;
	int		chunks_num;
	int		chunk_div;
	size_t	count;

	if (argc > 1)
	{
		count = 0;
		stacks = ft_stacknew();
		if (!stacks)
			ft_error(&stacks);
		if (ft_checkargs(&stacks, argv, &count))
		{
			sorted = ft_calloc(count, sizeof(int));
			if (!sorted)
				ft_error(&stacks);
			sorted = ft_lstoarray(sorted, stacks->head_a);
			sorted = ft_sortarray(sorted, count);
			chunk_div = ft_getchunkdiv(count);
			chunks_num = ft_addchunk(stacks->head_a, sorted, count / chunk_div + 1);
			stacks->head_a->prev->next = stacks->head_a;
			ft_algo(&stacks, chunks_num, count / chunk_div + 1);
			// ft_tests(&stacks);
			ft_result(stacks);
		}
	}
	return (0);
}
