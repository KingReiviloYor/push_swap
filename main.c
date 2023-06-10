/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:18:48 by oroy              #+#    #+#             */
/*   Updated: 2023/06/09 20:20:54 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printresults(t_stack *stacks)
{
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

void	ft_tests(t_stack **stacks)
{
	pa(stacks);
	pb(stacks);
	pb(stacks);
	sa(stacks);
	sb(stacks);
	ra(stacks);
	rb(stacks);
	pb(stacks);
	pb(stacks);
	pb(stacks);
	pb(stacks);
	rra(stacks);
	pa(stacks);
	pa(stacks);
	pa(stacks);
	rra(stacks);
	ss(stacks);
	rrr(stacks);
	rr(stacks);
}

void	ft_error(t_stack *stacks)
{
	ft_putstr_rtn_fd("Error\n", 2);
	if (stacks)
	{
		ft_lstclear(&stacks->head_a);
		if (stacks->tail_a)
			stacks->tail_a = NULL;
		free (stacks);
		stacks = NULL;
	}
	exit (1);
}

void	ft_parse(t_stack **stacks, char *arg)
{
	int		param;

	param = ft_atoi(arg);
	if (!(*stacks)->head_a)
	{
		(*stacks)->head_a = ft_lstnew(param, NULL);
		if (!(*stacks)->head_a)
			ft_error(*stacks);
		(*stacks)->tail_a = (*stacks)->head_a;
	}
	else
	{
		if (ft_lstchr((*stacks)->head_a, param))
			ft_error(*stacks);
		(*stacks)->tail_a = ft_lstnew(param, (*stacks)->tail_a);
		if (!(*stacks)->tail_a)
			ft_error(*stacks);
		(*stacks)->tail_a->previous->next = (*stacks)->tail_a;
	}
}

void	ft_checkargs(t_stack **stacks, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	j_save;
	char	*str;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
				j++;
			if (!argv[i][j])
				break ;
			j_save = j;
			if (!ft_isint(argv[i], &j))
				ft_error(*stacks);
			if (argv[i][j] || j_save)
			{
				str = ft_substr(argv[i], j_save, j - j_save);
				if (!str)
					ft_error(*stacks);
				ft_parse(stacks, str);
				free (str);
				str = NULL;
			}
			else
				ft_parse(stacks, argv[i]);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc > 1)
	{
		stacks = NULL;
		stacks = ft_stacknew();
		if (!stacks)
			ft_error(stacks);
		ft_checkargs(&stacks, argv);
		ft_tests(&stacks);
		ft_printresults(stacks);
	}
	return (0);
}
