/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:06:04 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/13 16:53:26 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//Appeler plusieurs fois avec des valeurs incrementales
// 7 uniquement pour des petit sets (5 par exemple)	
// sinon mettre 5 max pour etre instant
int	sort_bf(t_data *data, char **sol, int depth, int max_depth)
{
	//On essaie de limiter les operations dispo
	//char	*tab[11] = {"sa", "pb", "rra", "ra", "sb", "pa", "rrb", "rb", "ss", "rr", "rrr"};
	//char	*tab[11] = {"sa", "pb", "rra", "ra", "sb", "pa", "rrb", "rb"};
	char	*tab[11] = {"sa", "pb", "rra", "ra", "sb", "pa"};
	int		i;
	int j = 0;

	i = 0;
	if (checker_array(sol, data->s1, data->s1size))
		{
			printf("A : IS OK, max_depth : %d\n", max_depth);
			j = 0;
			while (j < 9)
			{
				printf("sol[%d] : %s\n", j, sol[j]);
				j++;
			}
			return (1);
		}
	while (i < 11 && depth < max_depth)
	{
		sol[depth] = tab[i];
		/*
		int j = 0;
		
		while (j < 4)
		{
			printf("sol[%d] : %s\n", j, sol[j]);
			j++;
		}
		*/
		// Obvious check a eviter
		// ie 2 sa colles ou 2 sb colles
		if ((sol[0] == tab[0] && sol[1] == tab[0])
			|| (sol[0] == tab[4] && sol[1] == tab[4])
)
			break ;
		//ajouter check stack est bien taille de l'initiale
		if (checker_array(sol, data->s1, data->s1size))
		{
			//printf("B : IS OK, max_depth : %d\n", max_depth);
			j = 0;
			while (j < 9)
			{
				//printf("sol[%d] : %s\n", j, sol[j]);
				j++;
			}
			return (1);
		}
		//printf("i : %d we go deeper : %d\n", i,  depth);
		if (sort_bf(data, sol, depth + 1, max_depth))
			return (1);	
		//Pour trouver toutes les solutions
		/*
		if (!checker_array(sol, data->s1, data->s1size))
		{
			sol[depth] = 0;
		}
		i++;
		*/
		//Pour trouver une seule solution
		if (!checker_array(sol, data->s1, data->s1size))
		{
			sol[depth] = 0;
			i++;
		}
		else
			break ;
	}
	//printf("return.i : %d deeper : %d\n", i,  depth);
	return (0);
}
