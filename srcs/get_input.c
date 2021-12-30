/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:16:12 by fle-blay          #+#    #+#             */
/*   Updated: 2021/12/30 11:02:51 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	**join_input(char *av[])
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

#include <stdio.h>

int	main(int ac, char *av[])
{
	(void)ac;
	char **ret;

	ret = join_input(++av);
	int i = 0;
	while (ret[i])
	{
		printf("ret : %s\n", ret[i]);
		free(ret[i++]);
	}
	free(ret);
	return (0);
}
