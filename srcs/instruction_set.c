/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:45:54 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/03 17:06:55 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	sa(t_data *data)
{
	t_list	*new_instruct;
	t_list	*oldl1nn;	
	t_list	*oldl1n;	
	oldl1n = data->l1->next;
	oldl1nn = data->l1->next->next;;

	if (!data->l1 || !data->l1->next)
		return (-1);
	new_instruct = ft_lstnew(&"sa");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	data->l1->next->next = data->l1;
	data->l1->next = oldl1nn;
	data->l1 = oldl1n;
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
	return (1);
}

int	ra(t_data *data)
{
	t_list	*index;
	t_list	*new_instruct;
	if (!data->l1 || !data->l1->next)
		return (-1);
	new_instruct = ft_lstnew(&"ra");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	index = data->l1;
	while (index->next->next)
		index = index->next;
	index->next->next = data->l1;
	data->l1 = index->next;
	index->next = NULL;
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
	return (1);
}


void	printer(void *content)
{
	if (!(ft_strncmp(content, "sa", 5)))
		ft_putstr_fd("sa", 1);
	if (!(ft_strncmp(content, "pb", 5)))
		ft_putstr_fd("pb", 1);
	if (!(ft_strncmp(content, "rra", 5)))
		ft_putstr_fd("rra", 1);
	ft_putstr_fd("\n", 1);
}

void	print_stack(void *content)
{
	ft_putnbr_fd(*(int*)content, 1);
	ft_putstr_fd("\n", 1);
}

void	print_instruct(t_list *start)
{
	ft_lstiter(start, &printer);
}

void	print_lst(t_data data)
{
	t_list	*i1;
	t_list	*i2;

	i1 = data.l1;
	i2 = data.l2;
	while (data.size-- && (i1 || i2))
	{
		if (i1)
		{
			ft_putnbr_fd(*((int *)(i1->content)), 1);
			i1 = i1->next;
		}
		ft_putstr_fd(" || ", 1);
		if (i2)
		{
			ft_putnbr_fd(*((int *)(i2->content)), 1);
			i2 = i2->next;
		}
		if (i1 || i2)
			ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("\n", 1);
}
