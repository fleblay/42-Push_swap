/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:01:12 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/26 09:34:44 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	do_instruct(void *content, t_data *test_data)
{
	if (!content || !test_data)
		return ;
	if (!(ft_strncmp(content, "sa", 5)))
		sa(test_data);
	else if (!(ft_strncmp(content, "pb", 5)))
		pb(test_data);
	else if (!(ft_strncmp(content, "rra", 5)))
		rra(test_data);
	else if (!(ft_strncmp(content, "ra", 5)))
		ra(test_data);
	else if (!(ft_strncmp(content, "sb", 5)))
		sb(test_data);
	else if (!(ft_strncmp(content, "pa", 5)))
		pa(test_data);
	else if (!(ft_strncmp(content, "rrb", 5)))
		rrb(test_data);
	else if (!(ft_strncmp(content, "rb", 5)))
		rb(test_data);
	else if (!(ft_strncmp(content, "ss", 5)))
		ss(test_data);
	else if (!(ft_strncmp(content, "rr", 5)))
		rr(test_data);
	else if (!(ft_strncmp(content, "rrr", 5)))
		rrr(test_data);
}

int	checker(t_list *instruct, long *input, int input_size)
{
	t_data	test_data;
	int		res;

	initialize(&test_data);
	test_data.s1 = input;
	test_data.l1 = listify(input, input_size);
	if (!test_data.l1)
		return (-1);
	update_size(&test_data);
	while (instruct)
	{
		do_instruct(instruct->content, &test_data);
		instruct = instruct->next;
	}
	res = is_sorted(test_data.l1);
	ft_lstclear(&(test_data.l1), (void (*)(void *))0);
	ft_lstclear(&(test_data.l2), (void (*)(void *))0);
	ft_lstclear(&(test_data.start), (void (*)(void *))0);
	return (res);
}

int	checker_array(char **tab, long *input, int input_size)
{
	t_data	test_data;
	int		res;
	int		i;
	int		l1sizeinit;

	initialize(&test_data);
	test_data.s1 = input;
	test_data.l1 = listify(input, input_size);
	if (!test_data.l1)
		return (-1);
	update_size(&test_data);
	l1sizeinit = test_data.l1size;
	i = 0;
	while (tab[i])
	{
		do_instruct(tab[i], &test_data);
		i++;
	}
	res = is_sorted(test_data.l1);
	ft_lstclear(&(test_data.l1), (void (*)(void *))0);
	ft_lstclear(&(test_data.l2), (void (*)(void *))0);
	ft_lstclear(&(test_data.start), (void (*)(void *))0);
	if (test_data.l1size != l1sizeinit)
		res = 0;
	return (res);
}
