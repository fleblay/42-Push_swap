/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:04:08 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/20 11:15:27 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ss(t_data *data)
{
	t_list	*new_instruct;

	new_instruct = ft_lstnew(&"ss");
	if (!new_instruct)
		custom_exit(0, data);
	ft_lstadd_back(&(data->start), new_instruct);
	sa(data);
	sb(data);
	return (1);
}

int	rr(t_data *data)
{
	t_list	*new_instruct;

	new_instruct = ft_lstnew(&"rr");
	if (!new_instruct)
		custom_exit(0, data);
	ft_lstadd_back(&(data->start), new_instruct);
	ra(data);
	rb(data);
	return (1);
}

int	rrr(t_data *data)
{
	t_list	*new_instruct;

	new_instruct = ft_lstnew(&"rrr");
	if (!new_instruct)
		custom_exit(0, data);
	ft_lstadd_back(&(data->start), new_instruct);
	rra(data);
	rrb(data);
	return (1);
}

int	update_size(t_data *data)
{
	t_list	*index;
	int		i;

	if (!data)
		return (-1);
	index = data->l1;
	i = 0;
	while (index)
	{
		i++;
		index = index->next;
	}
	data->l1size = i;
	i = 0;
	index = data->l2;
	while (index)
	{
		i++;
		index = index->next;
	}
	data->l2size = i;
	return (1);
}
