/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:56:52 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 11:58:14 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
}

int	printer2(void *content1, void *content2)
{
	int	opti;

	opti = 0;
	if (!(ft_strncmp(content1, "ra", 5)) && !(ft_strncmp(content2, "rb", 5)))
	{
		opti = 1;
		ft_putstr_fd("rr\n", 1);
	}
	if (!(ft_strncmp(content1, "rb", 5)) && !(ft_strncmp(content2, "ra", 5)))
	{
		opti = 1;
		ft_putstr_fd("rr\n", 1);
	}
	if (!(ft_strncmp(content1, "rra", 5)) && !(ft_strncmp(content2, "rrb", 5)))
	{
		opti = 1;
		ft_putstr_fd("rrr\n", 1);
	}
	if (!(ft_strncmp(content1, "rrb", 5)) && !(ft_strncmp(content2, "rra", 5)))
	{
		opti = 1;
		ft_putstr_fd("rrr\n", 1);
	}
	return (opti);
}

void	print_instruct(t_list *start)
{
	int	count;

	count = 0;
	while (start)
	{
		printer(start->content);
		count++;
		start = start->next;
	}
}

void	print_opti_instruct(t_list *start)
{
	int	count;

	count = 0;
	while (start)
	{
		if (start->next)
		{
			if (printer2(start->content, start->next->content))
			{
				count++;
				start = start->next;
			}
			else if (start)
			{
				printer(start->content);
				count++;
			}
		}
		else if (start)
		{
			printer(start->content);
			count++;
		}
		start = start->next;
	}
}
