/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:27:00 by oroy              #+#    #+#             */
/*   Updated: 2023/07/03 20:10:44 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(t_stack **stacks)
{
	ft_putstr_rtn_fd("Error\n", 2);
	if (*stacks)
	{
		ft_lstclear(&(*stacks)->head_a);
		free (*stacks);
		*stacks = NULL;
	}
	exit (1);
}
