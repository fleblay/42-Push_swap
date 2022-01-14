/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:44:59 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 11:09:59 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cheapest_move(t_data *data, int index_a, int index_b)
{
	int	cost_a;
	int	cost_b;

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

int	calculate_cheapest_move_b(t_data *data, int index_big, int index_low)
{
	int	cost_big;
	int	cost_low;

	if (index_big < data->l2size / 2)
		cost_big = index_big;
	else
		cost_big = data->l2size - index_big;
	if (index_low < data->l2size / 2)
		cost_low = index_low;
	else
		cost_low = data->l2size - index_low;
	if (cost_big <= cost_low)
		return (1);
	else
		return (2);
}

int	cost_mvtop(t_data *data, int value)
{
	int	pos_of_value;

	pos_of_value = get_index(data->l1, value);
	if (pos_of_value == -1)
		return (-1);
	if (pos_of_value <= (data->l1size / 2))
		return (pos_of_value);
	else
		return (data->l1size - pos_of_value);
}

int	cost_mvtopb(t_data *data, int value)
{
	int	pos_of_value;

	pos_of_value = get_index(data->l2, value);
	if (pos_of_value == -1)
		return (-1);
	if (pos_of_value <= (data->l2size / 2))
		return (pos_of_value);
	else
		return (data->l2size - pos_of_value);
}

int	print_infob(t_data *data, int *to_mvtopa, int *to_mvtopb, t_list *start)
{
	int		curr_val;	
	int		ssia;
	int		cost_to_topssia;
	int		cheapest_cost;

	cheapest_cost = data->l1size + data->l2size;
	while (start)
	{
		curr_val = *(int *)(start->content);
		if (get_smallest_sup_in_a(data, curr_val) != curr_val)
			ssia = get_smallest_sup_in_a(data, curr_val);
		else
			ssia = get_smallest_valuea(data);
		cost_to_topssia = cost_mvtop(data, ssia);
		if (cost_mvtopb(data, curr_val) + cost_to_topssia < cheapest_cost)
		{
			cheapest_cost = cost_mvtopb(data, curr_val) + cost_to_topssia;
			*to_mvtopb = curr_val;
			*to_mvtopa = ssia;
		}
		start = start->next;
	}
	return (0);
}
/*
int	print_infob(t_data *data, int *to_mvtopa, int *to_mvtopb)
{
	t_list	*start;
	int		curr_val;	
	int		cost_to_topb;
	int		ssia;
	int		cost_to_topssia;
	int		cheapest_cost;

	if (!data || !data->l2)
		return (-1);
	start = data->l2;
	cheapest_cost = data->l1size + data->l2size;
	while (start)
	{
		curr_val = *(int *)(start->content);
		cost_to_topb = cost_mvtopb(data, curr_val);
		if (get_smallest_sup_in_a(data, curr_val) != curr_val)
			ssia = get_smallest_sup_in_a(data, curr_val);
		else
			ssia = get_smallest_valuea(data);
		cost_to_topssia = cost_mvtop(data, ssia);
		printf("curr_val : %3d || cost_to_topb : %3d || ssia : %3d
		|| cost_ssia : %3d || total_cost : %3d\n"
		, curr_val, cost_to_topb, ssia, cost_to_topssia,
		cost_to_topb + cost_to_topssia);
		
		if (cost_to_topb + cost_to_topssia < cheapest_cost)
		{
			printf("changeing cheapest to %3d with value %3d\n"
			, cost_to_topb + cost_to_topssia, curr_val);
			cheapest_cost = cost_to_topb + cost_to_topssia;
			*to_mvtopb = curr_val;
			*to_mvtopa = ssia;
		}
		start = start->next;
	}
	return (0);
}
*/
