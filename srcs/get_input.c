/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:16:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/30 13:24:36 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdio.h>

static int	ft_isspace(int c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v' \
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atol(const char *nptr)
{
	int				i;
	long long int	nbr;
	int				sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (! ft_isdigit(nptr[i]))
	{
		if (nptr[i] != '-' && nptr[i] != '+')
			return (nbr);
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += nptr[i] - 48;
		i++;
	}
	return (sign * nbr);
}

char	**get_char_tab(char *av[])
{
	char	*ret;
	char	*tmp;
	int		i;

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
	return (ft_split(ret, ' '));
}

int	is_atoiable(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		//verif longueur max pour empecher les overflow coquins 
		//4294967296
		//surtout (longmax) -(long min) + nb_qui_rentre_dans_int
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
			{
				printf("non atoiable\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	*make_it_int(char **tab, int* size_tab)
{
	// a faire avec des long pour detecter erreurs !
	int	*tab_int = 0;
	int	i = 0;
	
	if (!tab || !is_atoiable(tab))
		return (NULL);
	while (tab[i])
		i++;
	*size_tab = i;
	tab_int = (int *)malloc((*size_tab) * sizeof(int));
	if (!tab_int)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		tab_int[i] = ft_atoi(tab[i]);
		i++;
	}
	return (tab_int);
}

int	is_uniq_and_int(int tab[], int size)
{
	int i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j] || tab[i] < -2147483648
				|| tab[i] > 2147483647)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	(void)ac;
	char **tab;
	int	size_tab = 0;
	int	*tab_int = 0;

	tab = get_char_tab(++av);
	int i = 0;
	while (tab[i])
	{
		printf("ret : %s\n", tab[i]);
		//free(tab[i]);
		i++;
	}
	//free(tab);

	tab_int = make_it_int(tab, &size_tab);
	if (!tab_int)
	{
		printf("not atoiable");
		return (0);
	}
	i = 0;
	while (i < size_tab)
	{
		printf("tab_int : %d\n", tab_int[i]);
		i++;
	}
	printf("isuniq and int %d\n", is_uniq_and_int(tab_int, size_tab));
	return (0);
}
