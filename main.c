/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 19:54:04 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	i;
	int		param;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		i = 1;
		stack_a = ft_stacknew();
		stack_b = ft_stacknew();
		// stack_b->head = ft_lstnew(0, NULL);
		while (argv[i])
		{
			if (!ft_isint(argv[i]))
			{
				// Eventually need to free here
				ft_putstr_rtn_fd("Error\n", 2);
				return (0);
			}
			param = ft_atoi(argv[i]);
			if (i == 1)
			{
				stack_a->head = ft_lstnew(param, NULL);
				stack_a->tail = stack_a->head;
			}
			else
			{
				if (ft_lstchr(stack_a->head, param))
				{
					// Eventually need to free here
					ft_putstr_rtn_fd("Error\n", 2);
					return (0);
				}
				stack_a->tail = ft_lstnew(param, stack_a->tail);
				stack_a->tail->previous->next = stack_a->tail;
			}
			i++;
		}
		pa(&stack_a, &stack_b);
		pb(&stack_b, &stack_a);
		pb(&stack_b, &stack_a);
		sa(&stack_a);
		sb(&stack_b);
		ra(&stack_a);
		rb(&stack_b);
		pb(&stack_b, &stack_a);
		pb(&stack_b, &stack_a);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		rra(&stack_a);
		pa(&stack_a, &stack_b);
		sa(&stack_a);
		rra(&stack_a);
		pb(&stack_b, &stack_a);
		pb(&stack_b, &stack_a);
		pb(&stack_b, &stack_a);
		sb(&stack_b);
		rrr(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		rr(&stack_a, &stack_b);
		ss(&stack_a, &stack_b);
		// For Testing Purposes
		ft_printf ("\n");
		ft_printf ("a	b");
		ft_printf ("\n\n");
		while (stack_a->head || stack_b->head)
		{
			if (stack_a->head)
			{
				ft_printf ("%i", stack_a->head->content);
				stack_a->head = stack_a->head->next;
			}
			ft_printf ("	");
			if (stack_b->head)
			{
				ft_printf ("%i", stack_b->head->content);
				stack_b->head = stack_b->head->next;
			}
			ft_printf ("\n");
		}
		ft_printf ("\n\n");

	}
	return (0);
}
