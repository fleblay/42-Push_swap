/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:15:15 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/20 11:10:34 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	cleaner(char *sol[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sol[i] = NULL;
		i++;
	}
}

static void	sol_printer(char *sol[], int max_depth)
{
	int	i;

	i = 0;
	while (i < max_depth && sol[i])
	{
		ft_putstr_fd(sol[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

int	iterator_bf(t_data *data)
{
	char	*sol[10];
	int		max_depth;

	cleaner(sol, 10);
	max_depth = 1;
	if (is_sorted(data->l1))
		return (1);
	while (max_depth < 10)
	{
		if (sort_bf(data, sol, 0, max_depth))
			break ;
		max_depth++;
	}
	if (max_depth == 10)
		return (0);
	else
	{
		sol_printer(sol, max_depth);
		return (1);
	}
}

int	sort_bf(t_data *data, char **sol, int depth, int max_depth)
{
	static char	*tab[6] = {"sa", "pb", "rra", "ra", "sb", "pa"};
	int			i;
	int			res;

	i = 0;
	while (i < 6 && depth < max_depth)
	{
		sol[depth] = tab[i];
		res = checker_array(sol, data->s1, data->s1size);
		if (res == -1)
			custom_exit(0, data);
		if (res == 1)
			return (1);
		if (sort_bf(data, sol, depth + 1, max_depth))
			return (1);
		i++;
	}
	sol[depth] = NULL;
	return (0);
}

/*
int	sort_bf(t_data *data, char **sol, int depth, int max_depth)
{
	static char	*tab[6] = {"sa", "pb", "rra", "ra", "sb", "pa"};
	int			i;

	i = 0;
	if (checker_array(sol, data->s1, data->s1size))
		return (1);
	while (i < 6 && depth < max_depth)
	{
		sol[depth] = tab[i];
		if ((sol[0] == tab[0] && sol[1] == tab[0])
			|| (sol[0] == tab[4] && sol[1] == tab[4]))
			break ;
		if (checker_array(sol, data->s1, data->s1size))
			return (1);
		if (sort_bf(data, sol, depth + 1, max_depth))
			return (1);
		if (!checker_array(sol, data->s1, data->s1size))
		{
			sol[depth] = 0;
			i++;
		}
		else
			break ;
	}
	return (0);
}
*/
