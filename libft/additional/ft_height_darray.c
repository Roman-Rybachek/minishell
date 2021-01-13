/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_darray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:34:14 by jeldora           #+#    #+#             */
/*   Updated: 2020/09/08 00:32:13 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_height_darray(char **map)
{
	int height;

	height = 0;
	while (*map)
	{
		map++;
		height++;
	}
	return (height);
}
