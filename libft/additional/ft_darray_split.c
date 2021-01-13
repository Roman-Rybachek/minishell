/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casteria <casteria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 04:39:29 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/26 17:17:14 by casteria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_darray_n_dup(char **array, int n)
{
	char	**result;
	int		i;

	i = n;
	if (!(result = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	result[i] = NULL;
	i = 0;
	while (array && array[i] && i < n)
	{
		result[i] = ft_strdup(array[i]);
		i++;
	}
	return (result);
}

static int		ft_sections(char **array, char *split)
{
	char	**arr;
	int		count;

	count = 0;
	arr = array;
	while (arr && *arr)
	{
		while (ft_strncmp(*arr, split, ft_strlen(*arr)) == 0)
			arr += 1;
		while (ft_strncmp(*arr, split, ft_strlen(*arr)) != 0)
			arr += 1;
		count++;
	}
	return (count);
}

char			***ft_darray_split(char **darray, char *split)
{
	char	***splited;
	int		size;
	int		i;
	char	**tmp;
	char	**start;

	i = 0;
	tmp = darray;
	size = ft_sections(tmp, split);
	splited = malloc(sizeof(char**) * (size + 1));
	splited[size] = NULL;
	while (i < size)
	{
		while (*tmp != NULL && ft_strncmp(*tmp, split, ft_strlen(*tmp)) == 0)
			tmp++;
		start = tmp;
		while (*tmp != NULL && ft_strncmp(*tmp, split, ft_strlen(*tmp)) != 0)
			tmp++;
		splited[i++] = ft_darray_n_dup(start, tmp - start);
	}
	return (splited);
}
