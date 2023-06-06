/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:39:33 by oroy              #+#    #+#             */
/*   Updated: 2023/06/06 14:53:09 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stacknew(void)
{
	t_stack	*t;

	t = ft_calloc(1, sizeof(t_stack));
	if (!t)
		return (NULL);
	t->head = NULL;
	t->tail = NULL;
	return (t);
}
