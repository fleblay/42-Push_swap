/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:16:12 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/04 12:40:31 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include "push_swap.h"

char	**get_char_tab(char *av[])
{
	char	*ret;
	char	*tmp;
	int		i;
	char	**final_ret;

	ret = ft_strdup("");
	if (!ret)
		return (NULL);
	i = 0;
	while (av[i])
	{
		tmp = ret;
		ret = ft_strjoin(ret, " ");
		free(tmp);
		if (!ret)
			return (NULL);
		tmp = ret;
		ret = ft_strjoin(ret, av[i++]);
		free(tmp);
		if (!ret)
			return (NULL);
	}
	final_ret = ft_split(ret, ' ');
	free(ret);
	return (final_ret);
}

long	*make_it_int(char **tab, int *size_tab, int *error)
{
	long	*tab_int;
	int		i;

	i = 0;
	if (!is_atoiable(tab))
	{
		*error = 1;
		return (NULL);
	}
	while (tab[i])
		i++;
	*size_tab = i;
	tab_int = (long *)malloc((*size_tab) * sizeof(long));
	if (!tab_int)
		return (NULL);
	i = -1;
	while (tab[++i] && !(*error))
		tab_int[i] = ft_atol(tab[i], error);
	if (!(*error) && !is_uniq(tab_int, *size_tab))
		*error = 1;
	return (tab_int);
}

long	*get_int_tab(char **av, int *size_tab)
{
	char	**tab;
	long	*tab_int;
	int		error;

	tab_int = NULL;
	error = 0;
	tab = get_char_tab(++av);
	if (!tab)
		return (NULL);
	tab_int = make_it_int(tab, size_tab, &error);
	destroy_tab(tab);
	if (error || !tab_int)
	{
		free(tab_int);
		custom_exit(error, NULL);
	}
	return (tab_int);
}

t_list	*listify(long *tab_int, int size)
{
	t_list	*start;
	t_list	*new_elem;
	int		i;

	i = 0;
	start = NULL;
	while (i < size)
	{
		new_elem = ft_lstnew(&(tab_int[i]));
		if (!new_elem)
		{
			ft_lstclear(&start, (void (*)(void *))0);
			return (NULL);
		}
		ft_lstadd_back(&start, new_elem);
		i++;
	}
	return (start);
}

#include <stdlib.h>
int	main(int ac, char *av[])
{
	(void)ac;
	t_data data;
	data.start = NULL;
	data.s1 = get_int_tab(av, &(data.s1size));
	data.l1 = listify(data.s1, data.s1size);
	data.l2 = listify(data.s1, 0);

	update_size(&data);
	print_lst(data);
	printf("\n");

	sa(&data);
	print_lst(data);
	printf("\n");

	pb(&data) && pb(&data) && pb(&data);
	print_lst(data);
	printf("\n");

	rra(&data);
	print_lst(data);
	printf("\n");

	ra(&data);
	print_lst(data);
	printf("\n");

	sb(&data);
	print_lst(data);
	printf("\n");

	pa(&data);
	print_lst(data);
	printf("\n");

	rrb(&data);
	print_lst(data);
	printf("\n");

	rb(&data);
	print_lst(data);
	printf("\n");

	/*
	move_top(&data, 12);
	print_lst(data);
	printf("\n");
	*/

	int	(*f)(t_data *);
	int	n;
	f = NULL;
	n = 0;
	mem_move_top(&data, 6, &n, &f);
	printf("n %d\n", n);
	if (f == &rra)
		printf("rra\n");
	else
		printf("ra\n");
	print_lst(data);
	printf("\n");

	print_instruct(data.start);

	//printf("index : %d\n", get_index(data.l1, 8));
	//printf("index : %d\n", get_index(data.l1, 12));
	custom_exit(0, &data);
	return (0);
}
