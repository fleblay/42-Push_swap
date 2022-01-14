/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:57:47 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/14 11:58:14 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
