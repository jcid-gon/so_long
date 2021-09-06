/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:39:15 by jcid-gon          #+#    #+#             */
/*   Updated: 2021/08/10 13:53:42 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd, int *ret);
void	ft_putstr_fd(char *s, int fd, int *ret);
void	ft_putnbr_fd(int n, int fd, int *ret);
void	ft_putuns_fd(int n, int fd, int *ret);
void	ft_int2base(unsigned long int dec, int base, int *ret);
void	ft_int2baseupp(unsigned int dec, int base, int *ret);

#endif
