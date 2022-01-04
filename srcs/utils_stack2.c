/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:57:09 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/04 17:20:50 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	get_index(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) != value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_value(t_list *start, int index)
{
	while (index--)
		start = start->next;
	return (*((int *)(start->content)));
}

int	is_p_sorted(t_data *data, int pivot)
{
	int	i;

	i = 0;
	while (i < data->l1size && get_value(data->l1, i) < pivot)
		i++;
	while (i < data->l1size)
	{
		if (get_value(data->l1, i) < pivot)
			return (0);
		i++;
	}
	return (1);
}

int	gnvap(t_data *data, int pivot)
{
	int	i;
	int	curr_val;

	i = 0;
	while (i < data->l1size)
	{
		curr_val = get_value(data->l1, i);
		if (curr_val >= pivot)
			return (curr_val);
		i++;
	}
	return (pivot);
}

int	gnvbp(t_data *data, int pivot)
{
	int	i;
	int	curr_val;

	i = data->l1size - 1;
	while (i > 0)
	{
		curr_val = get_value(data->l1, i);
		if (curr_val < pivot)
			return (curr_val);
		i--;
	}
	return (pivot);
}

#include <stdio.h>

void	p_sort(t_data *data, int pivot)
{
	(void)pivot;
	int	middle;

	printf("pivot : %d\n", middle = get_value(data->l1, data->l1size / 2));
	while (!is_p_sorted(data, middle))
	{
		swap(data, gnvap(data, middle), gnvbp(data, middle));
	}
}
