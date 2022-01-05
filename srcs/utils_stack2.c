/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:57:09 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/05 19:17:25 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	get_index(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) != value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_index_first_ge(t_list *start, int value)
{
	int	i;

	i = 0;
	while (start && *((int *)(start->content)) < value)
	{
		i++;
		start = start->next;
	}
	if (!start)
		return (-1);
	return (i);
}

int	get_value(t_list *start, int index)
{
	while (index--)
		start = start->next;
	return (*((int *)(start->content)));
}

int	is_p_sorted(t_data *data, int pivot, int start, int size)
{
	int	i;

	i = start;
	while (i < size && get_value(data->l1, i) < pivot)
		i++;
	while (i < size)
	{
		if (get_value(data->l1, i) < pivot)
			return (0);
		i++;
	}
	return (1);
}

int	gnvap(t_data *data, int pivot, int start, int size)
{
	int	i;
	int	curr_val;

	i = start;
	while (i < size)
	{
		curr_val = get_value(data->l1, i);
		if (curr_val >= pivot)
			return (curr_val);
		i++;
	}
	return (pivot);
}

int	gnvbp(t_data *data, int pivot, int start, int size)
{
	int	i;
	int	curr_val;

	i = size - 1;
	while (i > start)
	{
		curr_val = get_value(data->l1, i);
		if (curr_val < pivot)
			return (curr_val);
		i--;
	}
	return (pivot);
}

#include <stdio.h>

//not working
void	p_sort(t_data *data, int start, int size)
{
	int	middle;
	int	nxt_abv;
	int	nxt_blw;
	int	index_first_ge;

	if (size <= 2 || size - start < 2)
		return;
	middle = get_value(data->l1, size / 2);
	printf("pivot : %d\n", middle);
	printf("index pivot : %d\n", size / 2); 
	while (!is_p_sorted(data, middle, start, size))
	{
		nxt_abv = gnvap(data, middle, start, size);
		nxt_blw = gnvbp(data, middle, start, size);
		swap(data, nxt_abv, nxt_blw);
	}
	print_lst(*data);
	index_first_ge = get_index_first_ge(data->l1, middle);
	printf("index first ge pivot : %d\n", index_first_ge);
	//p_sort(data, 0, size - index_first_ge + 1);
	//p_sort(data, index_first_ge, size);
}

//working but swap not opti
void	p_sort2(t_data *data, int begin, int end)
{
	int	pivot;
	int save_begin;
	int save_end;

	if (begin >= end)
		return ;
	if (is_sorted(data->l2))
		return ;
	save_begin = begin;
	save_end = end;
	printf("ici1\n");
	pivot = get_value(data->l1, begin + (end - begin) / 2);
	while (begin <= end /*&& !is_sorted(data->l1)*/)
	{
		while (begin <= end && get_value(data->l1, begin) < pivot)
			begin++;
		while (end >= begin && get_value(data->l1, end) > pivot)
			end--;
		if (begin <= end)
		{
			printf("swapa\n");
			swap(data, get_value(data->l1, begin), get_value(data->l1, end));
			begin++;
			end--;
		}
	}
	print_lst(*data);
	p_sort2(data, save_begin, begin - 1);
	p_sort2(data, begin, save_end);
}	

//idem p_sort2 pour la stack b (pour le swap);
//attention : inversion des < et > pour les while pour avoir ordre invers avant de repousser)
void	p_sort2b(t_data *data, int begin, int end)
{
	int	pivot;
	int save_begin;
	int save_end;

	if (begin >= end)
		return ;
	if (is_sorted(data->l2))
		return ;
	save_begin = begin;
	save_end = end;
	printf("ici2\n");
	pivot = get_value(data->l2, begin + (end - begin) / 2);
	while (begin <= end && !is_rsorted(data->l2))
	{
		while (begin <= end && printf("begin : %d\n", begin) && get_value(data->l2, begin) > pivot)
			begin++;
		while (end >= begin && printf("end : %d\n", end) && get_value(data->l2, end) < pivot)
			end--;
		if (begin <= end)
		{
			printf("swapb\n");
			swapb(data, get_value(data->l2, begin), get_value(data->l2, end));
			begin++;
			end--;
		}
	}
	print_lst(*data);
	p_sort2b(data, save_begin, begin - 1);
	p_sort2b(data, begin, save_end);
}	

//idem p_sort2 mas avec tableau pour pouvoir utiliser swap2 qui n'a pas besoin
//de liste ordonee
void	p_sort_tab(t_data *data, long *tab, int begin, int end)
{
	int	pivot;
	int save_begin;
	int save_end;
	long	tmp;

	if (begin >= end)
		return ;
	save_begin = begin;
	save_end = end;
	//pivot = tab[begin + (end - begin) / 2];
	pivot = get_mediane(tab, begin, end);
	while (begin <= end)
	{
		while (begin <= end && tab[begin] < pivot)
			begin++;
		while (end >= begin && tab[end] > pivot)
			end--;
		if (begin <= end)
		{
			if (begin != end)
			{
				swap2(data,	tab[begin], tab[end]);
				tmp = tab[begin];
				tab[begin] = tab[end];
				tab[end] = tmp;
			}
			begin++;
			end--;
		}
	}
	print_lst(*data);
	p_sort_tab(data, tab, save_begin, begin - 1);
	p_sort_tab(data, tab, begin, save_end);
}

//try avec 2 stacks

void	p_sort_tab2(t_data *data, long *tab, int begin, int end)
{
	int	pivot;
	int save_begin;
	int save_end;
	long	tmp;

	if (begin >= end)
		return ;
	if (is_sorted(data->l1))
		return ;
	save_begin = begin;
	save_end = end;
	//pivot = tab[begin + (end - begin) / 2];
	pivot = get_mediane(tab, begin, end);
	printf("pivot value : %d\n", pivot);
	while (begin <= end && !is_sorted(data->l1))
	{
		while (begin <= end && tab[begin] < pivot)
			begin++;
		while (end >= begin && tab[end] > pivot)
			end--;
		if (begin <= end)
		{
			if (begin != end)
			{
				//to improve avec move_top ensuite
				printf("swap algo tab\n");
				swap(data, tab[begin], tab[end]);
				tmp = tab[begin];
				tab[begin] = tab[end];
				tab[end] = tmp;
			}
			begin++;
			end--;
		}
	}
	// move_top(data, tab[begin]); jusqu'a etre pivot sorted, inf au debut
	print_lst(*data);
	printf("begin : %ld\n", tab[begin]);
	move_top_to_other(data, begin, pb);
	print_lst(*data);
	p_sort2(data, 0, data->l1size - 1);
	p_sort2b(data, 0, data->l2size - 1);
	move_top_to_other(data, begin, pa);
}
int	get_mediane(long *tab, int begin, int end)
{
	int	i;
	int	*tmp_tab;
	int tmp;

	if (begin >=end)
		return (-1);
	tmp_tab = (int *)malloc((end - begin + 1) * sizeof(int));
	if (!tmp_tab)
		return (-1);
	i = -1;
	while ((++i) < end - begin + 1)
		tmp_tab[i] = tab[i + begin];
	i = 0;
	while (i < end - begin)
	{
		if (tmp_tab[i] > tmp_tab[i + 1])
		{
			tmp = tmp_tab[i];
			tmp_tab[i] = tmp_tab[i + 1];
			tmp_tab[i + 1] = tmp;
			i = 0;
		}
		else 
			i++;
	}
	return (tmp_tab[(end - begin) / 2]);
}

// int is_loop_sorted(t_list *lst);

int	is_sorted(t_list *lst)
{
	int curr_value;
	int ncurr_value;

	while (lst && lst->next)
	{
		curr_value = *((int *)(lst->content));
		ncurr_value = *((int *)(lst->next->content));
		if (curr_value > ncurr_value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_rsorted(t_list *lst)
{
	int curr_value;
	int ncurr_value;

	while (lst && lst->next)
	{
		curr_value = *((int *)(lst->content));
		ncurr_value = *((int *)(lst->next->content));
		if (curr_value < ncurr_value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
