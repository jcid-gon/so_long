/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:29:44 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/08/10 13:57:08 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(char flag, va_list list, int *ret)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(list, int), 1, ret);
	else if (flag == 's')
		ft_putstr_fd(va_arg(list, char *), 1, ret);
	else if (flag == 'p')
	{
		ft_putstr_fd("0x", 1, ret);
		ft_int2base(va_arg(list, uintptr_t), 16, ret);
	}
	else if (flag == 'd' || flag == 'i')
		ft_putnbr_fd (va_arg(list, int), 1, ret);
	else if (flag == 'u')
		ft_putuns_fd (va_arg(list, unsigned int), 1, ret);
	else if (flag == 'x')
		ft_int2base (va_arg(list, unsigned int), 16, ret);
	else if (flag == 'X')
		ft_int2baseupp (va_arg(list, unsigned int), 16, ret);
	else if (flag == '%')
		ft_putchar_fd('%', 1, ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_flags(str[i], list, &ret);
		}
		else
			ft_putchar_fd(str[i], 1, &ret);
		i++;
	}
	return (ret);
}
