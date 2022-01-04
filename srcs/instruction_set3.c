/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:04:08 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/04 10:56:00 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ss(t_data *data)
{
	t_list	*new_instruct;

	new_instruct = ft_lstnew(&"ss");
	if (!new_instruct)
		return (0);
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
		return (0);
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
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	rra(data);
	rrb(data);
	return (1);
}
