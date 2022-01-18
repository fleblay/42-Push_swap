/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:53:39 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/18 10:34:32 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void	custom_exit(int error, t_data *data)
{
	if (error)
		ft_putstr_fd("Error\n", 2);
	if (data)
	{
		ft_lstclear(&(data->l1), (void (*)(void *))0);
		ft_lstclear(&(data->l2), (void (*)(void *))0);
		ft_lstclear(&(data->start), (void (*)(void *))0);
		free(data->s1);
		free(data->sorted_s1);
		free(data->max_loop);
	}
	exit(0);
}

void	destroy_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	custom_exit_checker(int error, t_data *data, char *curr_instruct)
{
	if (error)
		ft_putstr_fd("Error\n", 2);
	if (curr_instruct)
		free(curr_instruct);
	if (data)
	{
		ft_lstclear(&(data->l1), (void (*)(void *))0);
		ft_lstclear(&(data->l2), (void (*)(void *))0);
		ft_lstclear(&(data->start), free);
		free(data->s1);
	}
	exit(0);
}
