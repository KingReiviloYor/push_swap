/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/05 18:26:06 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*save;

	if (*head && (*head)->next)
	{
		save = *head;
		*head = (*head)->next;
		save->next = (*head)->next;
		(*head)->next = save;
		ft_printf ("%s\n", "sa");
	}
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*save;

	if (*head_b)
	{
		save = (*head_b)->next;
		ft_lstadd_front(head_a, *head_b);
		*head_b = save;
		ft_printf ("%s\n", "pa");
	}
}

void	ra(t_list **head_a, t_list **tail_a)
{
	t_list	*save;

	if (*head_a && (*head_a)->next)
	{
		save = *head_a;
		*head_a = (*head_a)->next;
		save->previous = *tail_a;
		save->next = NULL;
		(*head_a)->previous = NULL;
		(*tail_a)->next = save;
		*tail_a = save;
		ft_printf ("%s\n", "ra");
	}
}

void	rra(t_list **head_a)
{
	t_list	*save;

	if (*head_a && (*head_a)->next)
	{
		save = ft_lst2ndlast(*head_a);
		ft_lstadd_front(head_a, save->next);
		save->next = NULL;
		ft_printf ("%s\n", "rra");
	}
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		param;
	t_list	*head_a;
	t_list	*head_b;
	t_list	*tail_a;

	if (argc > 1)
	{
		i = 1;
		head_b = ft_lstnew(0, NULL);
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
				head_a = ft_lstnew(param, NULL);
			else
			{
				if (ft_lstchr(head_a, param))
				{
					// Eventually need to free here
					ft_putstr_rtn_fd("Error\n", 2);
					return (0);
				}
				if (i == 2)
					tail_a = head_a;
				tail_a = ft_lstnew(param, tail_a);
				tail_a->previous->next = tail_a;
			}
			i++;
		}
		// sa(&head_a);
		// pa(&head_a, &head_b);
		// ra(&head_a, &tail_a);
		rra(&head_a);
		// For Testing Purposes
		while (head_a->next)
		{
			printf ("%i\n", head_a->content);
			head_a = head_a->next;
		}
		printf ("%i\n", head_a->content);
		if (head_b)
			printf ("%i\n", head_b->content);
	}
	return (0);
}
