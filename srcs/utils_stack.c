/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:43:12 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/07 16:51:19 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static int count = 0;

void	printer(void *content)
{
	if (!(ft_strncmp(content, "sa", 5)))
		ft_putstr_fd("sa", 1);
	if (!(ft_strncmp(content, "pb", 5)))
		ft_putstr_fd("pb", 1);
	if (!(ft_strncmp(content, "rra", 5)))
		ft_putstr_fd("rra", 1);
	if (!(ft_strncmp(content, "ra", 5)))
		ft_putstr_fd("ra", 1);
	if (!(ft_strncmp(content, "sb", 5)))
		ft_putstr_fd("sb", 1);
	if (!(ft_strncmp(content, "pa", 5)))
		ft_putstr_fd("pa", 1);
	if (!(ft_strncmp(content, "rrb", 5)))
		ft_putstr_fd("rrb", 1);
	if (!(ft_strncmp(content, "rb", 5)))
		ft_putstr_fd("rb", 1);
	if (!(ft_strncmp(content, "ss", 5)))
		ft_putstr_fd("ss", 1);
	if (!(ft_strncmp(content, "rr", 5)))
		ft_putstr_fd("rr", 1);
	if (!(ft_strncmp(content, "rrr", 5)))
		ft_putstr_fd("rrr", 1);
	ft_putstr_fd("\n", 1);
	count++;
}

void	print_instruct(t_list *start)
{
	ft_lstiter(start, &printer);
	printf("nb ope : %d\n", count);
}

void	print_size(t_data data)
{
	ft_putstr_fd("size a : ", 1);
	ft_putnbr_fd(data.l1size, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("size b : ", 1);
	ft_putnbr_fd(data.l2size, 1);
	ft_putstr_fd("\n", 1);
}

void	print_lst(t_data data)
{
	t_list	*i1;
	t_list	*i2;

	i1 = data.l1;
	i2 = data.l2;
	while (data.s1size-- && (i1 || i2))
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
	print_size(data);
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
