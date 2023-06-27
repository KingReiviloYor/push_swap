/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:14:05 by oroy              #+#    #+#             */
/*   Updated: 2023/06/22 15:32:50 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(int content, t_list *prev)
{
	t_list	*t;

	t = ft_calloc(1, sizeof(t_list));
	if (!t)
		return (NULL);
	t->chunk = 0;
	t->content = content;
	t->prev = prev;
	t->next = NULL;
	return (t);
}
