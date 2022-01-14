/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:41:30 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 10:32:55 by fle-blay         ###   ########.fr       */
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

int	get_index_first_g(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) <= value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_l(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) >= value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_ge(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) < value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_le(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) > value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}
