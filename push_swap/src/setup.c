/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:51:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/06 17:19:24 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	*setup_index(int argc, char **argv)
{
	int	i;
	int	*arr;
	int	size;

	i = 0;
	size = argc - 1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	bubble_sort(arr, size);
	return (arr);
}

static int	get_index(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size && arr[i] != n)
		i++;
	return (i + 1);
}

int	setup(t_register *ra, t_register *rb, int argc, char **argv)
{
	int	i;
	int	n;
	int	*arr;

	i = 1;
	ra->size = argc - 1;
	ra->topi = ra->size;
	ra->head = NULL;
	ra->tail = NULL;
	arr = setup_index(argc, argv);
	if (!arr)
		return (-1);
	while (arr && (i <= ra->size))
	{
		n = ft_atoi(argv[i++]);
		if (add_node(ra, new_node(n, get_index(arr, n, ra->size))) < 0)
			return (free(arr), arr = NULL, -1);
	}
	rb->size = 0;
	rb->topi = ra->size;
	rb->head = NULL;
	rb->tail = NULL;
	return (free(arr), arr = NULL, 0);
}
