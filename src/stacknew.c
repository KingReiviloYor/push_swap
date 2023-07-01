/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacknew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:39:33 by oroy              #+#    #+#             */
/*   Updated: 2023/06/30 22:14:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*stacknew(void)
{
	t_stack	*t;

	t = ft_calloc(1, sizeof(t_stack));
	if (!t)
		return (NULL);
	t->head_a = NULL;
	t->head_b = NULL;
	return (t);
}
