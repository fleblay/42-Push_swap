/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:45:54 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/03 12:35:36 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*int	sa(t_list **start, long *tab_int)
{
	t_list	*new_instruct;
	int		tmp;	

	new_instruct = ft_lstnew(&"1");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(start, new_instruct);
	tmp = tab_int[0];
	tab_int[0] = tab_int[1];
	tab_int[1] = tmp;
	return (1);
}*/

int	sa(t_data *data)
{
	t_list	*new_instruct;
	int		tmp;	

	new_instruct = ft_lstnew(&"1");
	if (!new_instruct)
		return (0);
	ft_lstadd_back(&(data->start), new_instruct);
	tmp = data->s1[0];
	data->s1[0] = data->s1[1];
	data->s1[1] = tmp;
	return (1);
}

void	printer(void *content)
{
	if (!(ft_strncmp(content, "1", 5)))
		ft_putstr_fd("sa", 1);
	ft_putstr_fd("\n", 1);
}

void	print_instruct(t_list *start)
{
	ft_lstiter(start, &printer);
}
