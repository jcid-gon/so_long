/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:10:23 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/08/10 13:40:26 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int *ret)
{
	long	number;

	number = n;
	while (number < 0)
	{
		ft_putchar_fd ('-', fd, ret);
		number = number * -1;
	}
	if (number >= 10)
		ft_putnbr_fd (number / 10, fd, ret);
	ft_putchar_fd ((number % 10) + '0', fd, ret);
}

void	ft_putuns_fd(int n, int fd, int *ret)
{
	unsigned int	number;

	number = n;
	if (number >= 10)
		ft_putnbr_fd (number / 10, fd, ret);
	ft_putchar_fd ((number % 10) + '0', fd, ret);
}
