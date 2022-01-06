/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_is2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:34:12 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/06 11:30:52 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	swapb(t_data *data, int val1, int val2)
{
	int	(*f1)(t_data *);
	int	(*f2)(t_data *);
	int	n1;
	int	n2;

	if (val1 == val2)
		return (0);
	if (get_index(data->l2, val1) < 0 || get_index(data->l2, val2) < 0)
		return (-1);
	update_size(data);
	mem_move_topb(data, val1, &n1, &f1);
	pa(data);
	update_size(data);
	mem_move_topb(data, val2, &n2, &f2);
	pa(data);
	sa(data);
	pb(data);
	while (n2--)
		f2(data);
	pb(data);
	while (n1--)
		f1(data);
	return (1);
}

//idem swap sans les 2 dernieres lignes
int	swap2(t_data *data, int val1, int val2)
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
	return (1);
}

int	move_top_to_other(t_data *data, int index, int (*f)())
{
	int	i;

	i = 0;
	while (i < index)
	{
		f(data);
		i++;
	}
	return (1);
}
