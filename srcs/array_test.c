/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:43:42 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/03 12:44:16 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_atoiable(char **tab)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (tab[i])
	{
		sign = 0;
		j = 0;
		if (ft_strlen(tab[i]) == 1 && (tab[i][0] == '-' || tab[i][0] == '+'))
			return (0);
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
				return (0);
			if (tab[i][j] == '-' || tab[i][j] == '+')
				sign++;
			j++;
		}
		if (sign > 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_uniq(long tab[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

