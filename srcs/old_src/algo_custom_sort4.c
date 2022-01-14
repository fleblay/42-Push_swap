/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_custom_sort4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:41:20 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/12 16:45:02 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	opti_sort4(t_data *data)
{
	int	pivot;
	//int	save_pivot[50] = {};
	int	old_l1size;
	int	old_l2size;
	int	i;
	int j;

	j = 0;
	printf("data_l1_size : %d\n", data->l1size);
	pivot = get_mediane_stack(data->l1, data->l1size);
	printf("pivot : %d\n", pivot);
	old_l1size = data->l1size;
	i = 0;
	while (i < old_l1size && get_index_first_l(data->l1, pivot) != -1 && data->l1size > 3)
	{
		if (*(int *)(data->l1->content) < pivot)
			pb(data);
		else
			ra(data);
		i++;
	}

	printf("nb instruct premier push a vers b val inf pivot: %d\n", ft_lstsize(data->start));

	i = 0;
	pivot = get_mediane_stack(data->l2, data->l2size);
	printf("pivot : %d\n", pivot);
	old_l2size = data->l2size;
	while (i < old_l2size && get_index_first_g(data->l2, pivot) != -1 && data->l2size > 3)
	{
		if (*(int *)(data->l2->content) > pivot)
			pa(data);
		else
			rb(data);
		i++;
	}
	printf("nb instruct premier push b vers a val sup pivot: %d\n", ft_lstsize(data->start));

	while (data->l2size)
	{
		move_topb(data, get_smallest_valueb(data));
		pa(data);
		ra(data);
	}
	printf("nb instruct premier tri insertion: %d\n", ft_lstsize(data->start));

	pivot = 25;
	printf("pivot : %d\n", pivot);
	i = 0;
	while (i < 25 - 1)
	{
		pb(data);
		i++;
	}

	printf("nb instruct premier push a vers b val inf pivot: %d\n", ft_lstsize(data->start));

	while (data->l2size)
	{
		move_topb(data, get_smallest_valueb(data));
		pa(data);
		ra(data);
	}
	//print_lst(*data);
	printf("nb instruct deuxieme tri insertion: %d\n", ft_lstsize(data->start));

	i = 0;
	while (i < 51)
	{
		pb(data);
		i++;
	}

	print_lst(*data);
	printf("nb instruct deuxieme tri insertion: %d\n", ft_lstsize(data->start));

	return ;

	j--;
	printf("doing b\n");

// ALGO 1 : POUSSER LE PLUS GRAND A CHAQUE FOIS
	/*	
	while (data->l2size)
	{
		push_biggest_valueb(data);
	}
	*/

	
// ALGO 2 : POUSSER LE PLUS PETIT SUP DE STACK A PAR RAPPORT AU TOP DE B VERS LE HAUT
	/*	
	while (data->l2size)
	{
		printf("index qui va etre move_top : %d\n", get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content))));
		move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		pa(data);
	}
	*/
	
	//print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
	
	printf("doing b part 2\n");

// ALGO 3 : POUSSER LE PLUS PETIT SUP DE STACK B PAR RAPPORT AU TOP DE A VERS LE HAUT
	///*
	while (data->l2size)
	{
		printf("index qui va etre move_top : %d\n", get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content))));
		move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		pa(data);
	}
	//*/
// ALGO 4 : regarder cout de 2 et cout de 3 et faire le moins cher
// PB quand switch algo
//
	/*
	int index_try_a;
	int index_try_b;
	int k = 0 ;
	while (data->l2size && k != 1)// && k < 2)// > data->s1size / 2)
	{
		index_try_a = get_index(data->l1, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
		index_try_b = get_index(data->l2, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
		printf("nb top b : %d", *(int *)(data->l2->content));
		printf("||index algo 2 : %d", index_try_a);
		printf("|| index algo 3: %d", index_try_b);
		printf("cheapest move : %c\n", calculate_cheapest_move(data, index_try_a, index_try_b));
		if (index_try_b == -1|| *(int *)(data->l2->content) == 92)
			k = 1;
			//break ;
		{
			if (index_try_a != -1 && calculate_cheapest_move(data, index_try_a, index_try_b) == 'a')
			{
				printf("doing algo 2 on : %d\n", *(int *)(data->l2->content));
				move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
				pa(data);
			}
			else if (index_try_b != -1)
			{
				//push_biggest_valueb(data);
				printf("doing algo 3 on : %d\n",get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
				move_topb(data, get_biggest_inf_in_b(data, *(int *)(data->l1->content)));
				pa(data);
			}
			else 
			{
				printf("Default, pushing biggest %d\n", get_biggest_valueb(data));
				push_biggest_valueb(data);
				
				//printf("error at some point : doing algo 2\n");
				//move_top(data, get_smallest_sup_in_a(data, *(int *)(data->l2->content)));
				//pa(data);

			}
		}
	}
	*/

	//sort_3b(data);
	/*
	while (data->l2size)
		pa(data);
		*/
	print_lst(*data);
	printf("nb instruct : %d\n", ft_lstsize(data->start));
//	printf("nb misfit : %d\n", spot_misfits(data->l1));
	
}
