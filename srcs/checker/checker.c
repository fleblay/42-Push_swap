/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:38:40 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/20 12:11:50 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "push_swap.h"

static void	load_input_checker(t_data *data)
{
	char	*curr_instruct;
	t_list	*new_elem;

	curr_instruct = get_next_line(0);
	while (curr_instruct)
	{
		new_elem = ft_lstnew(curr_instruct);
		if (!new_elem)
			custom_exit_checker(1, data, curr_instruct);
		ft_lstadd_back(&(data->start), new_elem);
		if (!check_input(data->start))
			custom_exit_checker(1, data, NULL);
		curr_instruct = get_next_line(0);
	}
	if (!check_input(data->start))
		custom_exit_checker(1, data, curr_instruct);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 1)
		return (0);
	initialize(&data);
	data.s1 = get_int_tab(av, &(data.s1size));
	data.l1 = listify(data.s1, data.s1size);
	if (!data.s1 || !data.l1)
		custom_exit_checker(0, &data, NULL);
	update_size(&data);
	load_input_checker(&data);
	if (checker(data.start, data.s1, data.s1size))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	custom_exit_checker(0, &data, NULL);
	return (0);
}
