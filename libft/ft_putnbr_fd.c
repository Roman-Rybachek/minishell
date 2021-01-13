/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:34:27 by jeldora           #+#    #+#             */
/*   Updated: 2020/05/04 13:36:22 by jeldora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int i;

	i = 1;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2", fd);
			n = 147483648;
		}
		else
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
	}
	while (n / i > 9)
		i *= 10;
	while (i /= 10 != 1)
	{
		ft_putchar_fd(n / i + 48, fd);
		n %= i;
		i /= 10;
	}
}
