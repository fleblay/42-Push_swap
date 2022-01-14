/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:45:54 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/04 10:52:29 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	sa(t_data *data)
{
	t_list	*new_instruct;
	t_list	*oldl1nn;	
	t_list	*oldl1n;	

	if (!data->l1 || !data->l1->next)
		return (-1);
	new_instruct = ft_lstnew(&"sa");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	oldl1n = data->l1->next;
	oldl1nn = data->l1->next->next;
	data->l1->next->next = data->l1;
	data->l1->next = oldl1nn;
	data->l1 = oldl1n;
	update_size(data);
	return (1);
}

int	pb(t_data *data)
{
	t_list	*oldl1;
	t_list	*new_instruct;

	if (!data->l1)
		return (-1);
	new_instruct = ft_lstnew(&"pb");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	oldl1 = data->l1;
	data->l1 = data->l1->next;
	ft_lstadd_front(&(data->l2), oldl1);
	update_size(data);
	return (1);
}

int	ra(t_data *data)
{
	t_list	*oldl1n;
	t_list	*index;
	t_list	*new_instruct;

	if (!data->l1 || !data->l1->next)
		return (-1);
	new_instruct = ft_lstnew(&"ra");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	oldl1n = data->l1->next;
	index = data->l1;
	while (index->next)
		index = index->next;
	index->next = data->l1;
	data->l1->next = NULL;
	data->l1 = oldl1n;
	update_size(data);
	return (1);
}

int	rra(t_data *data)
{
	t_list	*index;
	t_list	*new_instruct;

	if (!data->l1 || !data->l1->next)
		return (-1);
	new_instruct = ft_lstnew(&"rra");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	index = data->l1;
	while (index->next->next)
		index = index->next;
	index->next->next = data->l1;
	data->l1 = index->next;
	index->next = NULL;
	update_size(data);
	return (1);
}
