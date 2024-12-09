/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:27:00 by oroy              #+#    #+#             */
/*   Updated: 2024/12/08 23:53:22 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(t_stack **stacks)
{
	ft_putstr_fd("Error\n", 2);
	if (*stacks)
	{
		ft_lstclear(&(*stacks)->head_a);
		free (*stacks);
		*stacks = NULL;
	}
	exit (1);
}
