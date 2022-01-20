/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:52:47 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/20 12:27:29 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	sb(t_data *data)
{
	t_list	*new_instruct;
	t_list	*oldl2nn;	
	t_list	*oldl2n;	

	if (!data->l2 || !data->l2->next)
		return (-1);
	new_instruct = ft_lstnew(&"sb");
	if (!new_instruct)
		custom_exit_checker(0, data, NULL);
	ft_lstadd_back(&(data->start), new_instruct);
	oldl2n = data->l2->next;
	oldl2nn = data->l2->next->next;
	data->l2->next->next = data->l2;
	data->l2->next = oldl2nn;
	data->l2 = oldl2n;
	update_size(data);
	return (1);
}

int	pa(t_data *data)
{
	t_list	*oldl2;
	t_list	*new_instruct;

	if (!data->l2)
		return (-1);
	new_instruct = ft_lstnew(&"pa");
	if (!new_instruct)
		custom_exit_checker(0, data, NULL);
	ft_lstadd_back(&(data->start), new_instruct);
	oldl2 = data->l2;
	data->l2 = data->l2->next;
	ft_lstadd_front(&(data->l1), oldl2);
	update_size(data);
	return (1);
}

int	rb(t_data *data)
{
	t_list	*oldl2n;
	t_list	*index;
	t_list	*new_instruct;

	if (!data->l2 || !data->l2->next)
		return (-1);
	new_instruct = ft_lstnew(&"rb");
	if (!new_instruct)
		custom_exit_checker(0, data, NULL);
	ft_lstadd_back(&(data->start), new_instruct);
	oldl2n = data->l2->next;
	index = data->l2;
	while (index->next)
		index = index->next;
	index->next = data->l2;
	data->l2->next = NULL;
	data->l2 = oldl2n;
	update_size(data);
	return (1);
}

int	rrb(t_data *data)
{
	t_list	*index;
	t_list	*new_instruct;

	if (!data->l2 || !data->l2->next)
		return (-1);
	new_instruct = ft_lstnew(&"rrb");
	if (!new_instruct)
		custom_exit_checker(0, data, NULL);
	ft_lstadd_back(&(data->start), new_instruct);
	index = data->l2;
	while (index->next->next)
		index = index->next;
	index->next->next = data->l2;
	data->l2 = index->next;
	index->next = NULL;
	update_size(data);
	return (1);
}
