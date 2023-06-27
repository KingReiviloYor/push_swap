/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:30:43 by oroy              #+#    #+#             */
/*   Updated: 2023/06/22 14:09:52 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	*ft_sortarray(int *arr, size_t count)
// {
// 	size_t	i;
// 	int	save;

// 	if (!count)
// 		return (arr);
// 	i = 0;
// 	save = 0;
// 	while (i < count)
// 	{
// 		if (arr[i] > arr[i + 1])
// 		{
// 			save = arr[i + 1];
// 			arr[i + 1] = arr[i];
// 			arr[i] = save;
// 		}
// 		i++;
// 	}
// 	return (ft_sortarray(arr, count - 1));
// }

int	*ft_sortarray(int *arr, size_t count)
{
	size_t	i;
	int	save;

	save = 0;
	while (count)
	{
		i = 0;
		while (i < count - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				save = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = save;
			}
			i++;
		}
		count--;
	}
	return (arr);
}

// int	main(void)
// {
// 	int	arr[9] = {1, 21, 15, -44, 5, 7, 8, 20, 0};
// 	int	*sorted;
// 	int i;

// 	i = 0;
// 	sorted = ft_calloc(10, sizeof(int));
// 	sorted = ft_sortarray(arr, 9);
// 	printf ("Done Done");
// 	printf ("\n");
// 	while (i < 9)
// 	{
// 		printf ("%i ", sorted[i]);
// 		i++;
// 	}
// 	return (0);
// }
