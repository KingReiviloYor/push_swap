/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:20:10 by oroy              #+#    #+#             */
/*   Updated: 2023/07/03 19:23:58 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	parsing(t_stack **stacks, int param, char **str, int *algo_do)
{
	t_list	*save;

	free (*str);
	*str = NULL;
	save = NULL;
	if (!(*stacks)->head_a)
	{
		(*stacks)->head_a = ft_lstnew(param, save);
		if (!(*stacks)->head_a)
			ft_error(stacks);
		(*stacks)->head_a->prev = (*stacks)->head_a;
	}
	else
	{
		if (ft_lstchr((*stacks)->head_a, param))
			ft_error(stacks);
		save = (*stacks)->head_a->prev;
		(*stacks)->head_a->prev = ft_lstnew(param, save);
		if (!(*stacks)->head_a->prev)
			ft_error(stacks);
		save->next = (*stacks)->head_a->prev;
		if (param < save->content)
			*algo_do = 1;
	}
}
