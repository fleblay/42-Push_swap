/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:16:37 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/26 09:35:00 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_in_loop_max_sorted(t_data *data, int value)
{
	int	i;

	i = 0;
	while (i < data->ml_size)
	{
		if (data->max_loop[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	get_biggest_inf_in_a(t_data *data, int value)
{
	t_list	*start;
	int		max_min;

	start = data->l1;
	if (!start)
		return (value);
	max_min = get_smallest_valuea(data);
	if (max_min > value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) > max_min
			&& *((int *)(start->content)) < value)
			max_min = *((int *)(start->content));
		start = start->next;
	}
	return (max_min);
}

int	get_smallest_sup_in_a(t_data *data, int value)
{
	t_list	*start;
	int		min_max;

	start = data->l1;
	if (!start)
		return (value);
	min_max = get_biggest_valuea(data);
	if (min_max < value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) < min_max
			&& *((int *)(start->content)) > value)
			min_max = *((int *)(start->content));
		start = start->next;
	}
	return (min_max);
}

int	get_smallest_sup_in_b(t_data *data, int value)
{
	t_list	*start;
	int		min_max;

	start = data->l2;
	if (!start)
		return (value);
	min_max = get_biggest_valueb(data);
	if (min_max < value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) < min_max
			&& *((int *)(start->content)) > value)
			min_max = *((int *)(start->content));
		start = start->next;
	}
	return (min_max);
}

int	get_biggest_inf_in_b(t_data *data, int value)
{
	t_list	*start;
	int		max_min;

	start = data->l2;
	if (!start)
		return (value);
	max_min = get_smallest_valueb(data);
	if (max_min > value)
		return (value);
	while (start)
	{
		if (*((int *)(start->content)) > max_min
			&& *((int *)(start->content)) < value)
			max_min = *((int *)(start->content));
		start = start->next;
	}
	return (max_min);
}
