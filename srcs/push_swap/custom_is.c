/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:15:19 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/26 09:32:03 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	move_top(t_data *data, int value)
{
	int	pos_of_value;

	pos_of_value = get_index(data->l1, value);
	if (pos_of_value == -1)
		return (-1);
	if (pos_of_value <= (data->l1size / 2))
		while (get_index(data->l1, value))
			ra(data);
	else
		while (get_index(data->l1, value))
			rra(data);
	return (1);
}

int	move_topb(t_data *data, int value)
{
	int	pos_of_value;

	pos_of_value = get_index(data->l2, value);
	if (pos_of_value == -1)
		return (-1);
	if (pos_of_value <= (data->l2size / 2))
		while (get_index(data->l2, value))
			rb(data);
	else
		while (get_index(data->l2, value))
			rrb(data);
	return (1);
}

int	mem_move_top(t_data *data, int value, int *n_iter, int (**f_inv)())
{
	int	n;
	int	pos_of_value;

	n = 0;
	pos_of_value = get_index(data->l1, value);
	if (pos_of_value <= (data->l1size / 2))
	{
		*f_inv = &rra;
		while (get_index(data->l1, value))
		{
			n++;
			ra(data);
		}
	}
	else
	{
		*f_inv = &ra;
		while (get_index(data->l1, value))
		{
			n++;
			rra(data);
		}
	}
	*n_iter = n;
	return (1);
}

int	mem_move_topb(t_data *data, int value, int *n_iter, int (**f_inv)())
{
	int	n;
	int	pos_of_value;

	n = 0;
	pos_of_value = get_index(data->l2, value);
	if (pos_of_value <= (data->l2size / 2))
	{
		*f_inv = &rrb;
		while (get_index(data->l2, value))
		{
			n++;
			rb(data);
		}
	}
	else
	{
		*f_inv = &rb;
		while (get_index(data->l2, value))
		{
			n++;
			rrb(data);
		}
	}
	*n_iter = n;
	return (1);
}

int	swap(t_data *data, int val1, int val2)
{
	int	(*f1)(t_data *);
	int	(*f2)(t_data *);
	int	n1;
	int	n2;

	if (val1 == val2)
		return (0);
	if (get_index(data->l1, val1) < 0 || get_index(data->l1, val2) < 0)
		return (-1);
	update_size(data);
	mem_move_top(data, val1, &n1, &f1);
	pb(data);
	update_size(data);
	mem_move_top(data, val2, &n2, &f2);
	pb(data);
	sb(data);
	pa(data);
	while (n2--)
		f2(data);
	pa(data);
	while (n1--)
		f1(data);
	return (1);
}
