/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:25:13 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/12 13:20:41 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	r_get_index_first_g(t_list *start, int value)
{
	int	i;
	int	save_i;

	i = 0;
	save_i = -1;
	if (!start)
		return (-1);
	while (start)
	{
		if (*((int *)(start->content)) > value)
			save_i = i;
		start = start->next;
		i++;
	}
	return (save_i);
}

int	r_get_index_first_l(t_list *start, int value)
{
	int	i;
	int	save_i;

	i = 0;
	save_i = -1;
	if (!start)
		return (-1);
	while (start)
	{
		if (*((int *)(start->content)) < value)
			save_i = i;
		i++;
		start = start->next;
	}
	return (save_i);
}

int	r_get_index_first_ge(t_list *start, int value)
{
	int	i;
	int	save_i;

	i = 0;
	save_i = -1;
	if (!start)
		return (-1);
	while (start)
	{
		if (*((int *)(start->content)) >= value)
			save_i = i;
		i++;
		start = start->next;
	}
	return (save_i);
}

int	r_get_index_first_le(t_list *start, int value)
{
	int	i;
	int	save_i;

	i = 0;
	save_i = -1;
	if (!start)
		return (-1);
	while (start)
	{
		if (*((int *)(start->content)) <= value)
			save_i = i;
		i++;
		start = start->next;
	}
	return (save_i);
}

int	calculate_cheapest_move(t_data *data, int index_a, int index_b)
{
	int cost_a;
	int cost_b;

	if (index_a < data->l1size / 2)
		cost_a = index_a;
	else
		cost_a = data->l1size - index_a;
	if (index_b < data->l2size / 2)
		cost_b = index_b;
	else
		cost_b = data->l2size - index_b;
	if (cost_a < cost_b)
		return ('a');
	if (cost_a == cost_b)
		return ('=');
	else
		return ('b');
}
